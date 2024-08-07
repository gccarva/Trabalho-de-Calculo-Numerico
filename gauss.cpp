#include"matrix.hpp"
#include<stack>
#include<iostream>
double abs(double a){
    return a > 0 ? a : -a;
}
void escalonamento(matrix &a, matrix &b, std::stack < std::pair<int, int>> swap)
{
    double zero = 0.0000000001f;
    int j;
    double coef; 
    for (int i = 0; i < a.i-1 && i<a.j; i++){
        //pode dar problema
        if (abs(a.valores[i][i]) < zero){
            for (j = i + 1; j < a.i;j++){
                if(abs(a.valores[j][i]) > zero){
                    swap.push(std::make_pair(i, j));
                    a.swap(i, j);
                    b.swap(i, j);
                    break;
                }
            }
            //a.print();
            if(j == a.i){
                //a.print();
                std::cout << "impossivel de fazer o escalonamento na linha " << i << "\n";
                exit(1);
            }
        }
        for (int l = i + 1; l < a.i;l++){
            coef = a.valores[l][i] / a.valores[i][i];
        //    std::cout << "coef" << coef << std::endl;
            for (int k = i; k < a.j;k++){
                a.valores[l][k] -= coef * (a.valores[i][k]);
            }
            for (int k = 0; k < b.j;k++)
                b.valores[l][k] -= coef * (b.valores[i][k]);
        }
    }
}
matrix* eliminacao(matrix &a,matrix &b){
    if(a.i != b.i || a.i != a.j){
        std::cout << "impossiver fazer a eliminacao" << std::endl;
        exit(1);
    };
    std::stack<std::pair<int,int>> aswap;
    escalonamento(a, b, aswap);
    double zero = 0.0000000001f;
    if(abs(a.valores[a.i-1][a.i-1]) <zero){
        std::cout << "impossivel fazer eliminacao ultima linha tudo 0" << std::endl;
        exit(1);
    }
    matrix *x = new matrix(a.i, 1);
    double acumular;
    for (int l = a.i - 1; l > -1; l--)
    {
        acumular = 0;
        for (int k = l+1; k <= a.i - 1;k++){
            acumular += x->valores[k][0]*a.valores[l][k];
        }
        x->valores[l][0] = (b.valores[l][0] - acumular) / (a.valores[l][l]);
    }
    //a.print();
   //b.print();
    return x;
}