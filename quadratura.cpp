#include "gauss.hpp"
#include<cmath>
double my_pow(const double x,const int y){
    double resposta = 1;
    for (int i = 0; i < y; i++)
        resposta *= x;
    return resposta;
}
matrix* generate_f( const matrix*x){
    if(x->i & 1 || x->j != 1){
        std::cout << "impossible generate f";
        exit(1);
    }
    matrix *answer = new matrix(x->i, 1);
    for (int i = 0; i < x->i; i++ ){
        answer->valores[i][0] = 0;
        for (int j = 0; j < x->i >> 1;j++){
            answer->valores[i][0] -= my_pow(x->valores[j][0], i) * x->valores[j+(x->i >> 1)][0];
        }
        if(i % 2 == 0){
            answer->valores[i][0] += (double)2.0f / (double)(i + 1);
        }
    }
    return answer;
}
matrix*generate_jacobian(const matrix *x){
    if(x->i & 1 || x->j != 1){
        std::cout << "impossible generate jacobina";
        exit(1);
    }
    matrix *answer = new matrix(x->i, x->i);
    for (int i = 0; i < x->i;i++){
        for (int j = 0; j < x->i >> 1;j++){
            answer->valores[i][j] = x->valores[j + (x->i >> 1)][0] * i * my_pow(x->valores[j][0], i-1);
            answer->valores[i][j + (x->i >> 1)] = my_pow(x->valores[j][0], i);
        }
    }
    return answer;
}
void distribui(const matrix *y, matrix *x ,matrix *a){
    if(y->i != x->i*2){
        std::cout << "impossivel distribuir" << std::endl;
        exit(1);
    }
    for (int i = 0; i < x->i;i++){
        x->valores[i][0] = y->valores[i][0];
        a->valores[i][0] = y->valores[i + x->i][0];
    }

}
double erro(const matrix *x, const matrix *y){
    if(x->i != y->i){
        std::cout << "impossivel calcular o erro" << std::endl;
        exit(1);
    }
    double erro=0;
    for (int i = 0; i < x->i;i++){
        erro += fabs(x->valores[i][0] - y->valores[i][0]);
    }
    return erro;
}
matrix *sum(const matrix *a,const matrix*b){
    if(a->i != b->i || a->j != b->j){
        std::cout << " impossivel somar" << std::endl;
    }
    matrix *soma = new matrix(a->i, a->j);
    for (int i = 0; i < a->i; i++){
        for (int j = 0; j < a->j;j++){
            soma->valores[i][j] = a->valores[i][j] + b->valores[i][j];
            if(soma->valores[i][j] < 1e-10f){}
                //soma->valores[i][j] = 0.1f;
        }
    }
    return soma;
}
void calcular_quad(matrix *x, double erro1){
    double errott = 10;
    matrix *x_antigo = new matrix(x->i, 1);
    for (int i = 0; i < x->i; i++)
        x_antigo->valores[i][0] = x->valores[i][0];
    int i = 0;
    while(errott > erro1){
        matrix *jacobian = generate_jacobian(x_antigo);
         jacobian->print();
        matrix *f = generate_f(x_antigo);
      //  f->print();
        matrix *y = eliminacao(*jacobian, *f);
      //  y->print();
        matrix *x_novo = sum(x_antigo,y);
        i += 1;
        errott = erro(x_novo, x_antigo);
        delete x_antigo;
        delete jacobian;
        delete f;
        delete y;
        x_antigo = x_novo;
        x_novo->print();
        std::cout << i << " " << errott << std::endl;
    }
    x = x_antigo;
    x_antigo->print();
    return;
}