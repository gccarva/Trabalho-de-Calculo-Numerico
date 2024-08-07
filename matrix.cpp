#include<cstdlib>
#include<iostream>
#include "matrix.hpp"
matrix::matrix(const int i,  const int j){
   // std::cout << "alloc " << i << " " << j << std::endl;
    this->i = i;
    this->j = j;
    valores = new double *[i];
    if (valores == nullptr)
    {
        std::cout << "impossible to allocate memory" << std::endl;
        exit(1);
            }
            for (int k= 0; k < i;k++){
                valores[k] = new double[j];
                if(valores[k]== nullptr){
                std::cout << "impossible to allocate memory" << std::endl;
                exit(1);
            }}
        };
matrix::matrix(const matrix &other) = default;
matrix& matrix::operator=(const matrix &other) = default;
matrix::matrix(matrix &&other) = default;
matrix& matrix::operator=(matrix &&other) = default;
matrix::~matrix(){
         //   std::cout << "delete matrix" << std::endl;
            for (int l = 0; l < i;l++){
                delete valores[l];
            }
            delete valores;
        };
        inline bool matrix::valid(const int i, const int j) const{
            return i < this->i && j < this->j;
        }
        inline double matrix::get(const int i,const int j) const
        {
            if(valid(i,j)) return valores[i][j];
            else{
                std::cout << "dimensions " << this->i << " " << this->j << std::endl;
                std::cout << "invalid input " << i+1 << " " << j+1 << std::endl;
                exit(1);
            }
        }
        inline void matrix::set(const int i,const int j, const double value){
          //  std::cout << "set " << i << " " << j << " " << value << std::endl;
            if(valid(i,j)) valores[i][j] = value;
            else{
                std::cout << "dimensions " << this->i<< " " << this->j<< std::endl;
                std::cout << "invalid input " << i+1 << " " << j+1 << std::endl;
                exit(1);
            }
        }
        matrix* matrix::transposta() const {
            matrix *transposta = new matrix(this->j, this->i);
            for (int k = 0; k < j; k++){
                for (int l = 0; l < i;l++){

                    transposta->set(k, l, get(l, k));
                }
            }
            return transposta;
        }
        matrix* matrix::operator*(const matrix &other) const {
            if(j != other.i){
                std::cout << "impossible to multiply" << std::endl;
                exit(1);
            }
            matrix *answer = new matrix(i, other.j);
            double numero=0;
            for (int l = 0; l < i;l++)
            for (int k = 0; k < other.j; k++ ){
                numero = 0;
                for (int m = 0; m < j;m++){
                    numero += valores[l][m] * other.valores[m][k];
                }
                answer->valores[l][k] = numero;
            }
            return answer;
        }
        matrix* matrix::operator+(const matrix &other) const{
            if(j!=other.j || i!=other.i){
            std::cout << "impossible sum"<<i<<j<<other.i<<other.j << std::endl;
            exit(1);
            }
            matrix *answer = new matrix(i, j);
            for (int l = 0; l < i; l++){
            for (int k = 0; k < j;k++){
                answer->valores[l][k] = valores[l][k] + other.valores[l][k];
            }
            }
            return answer;
        }
        matrix* matrix::operator-(const matrix &other) const{
            if(j!=other.j || i!=other.i){
            std::cout << "impossible sub" << std::endl;
            exit(1);
            }
            matrix *answer = new matrix(i, j);
            for (int l = 0; l < i; l++){
            for (int k = 0; k < j;k++){
                answer->valores[l][k] = valores[l][k] - other.valores[l][k];
            }
            }
            return answer;
        }
    void matrix::read_matrix(){
        for (int l = 0; l < i;l++){
            for (int k = 0; k < j;k++){
                std::cin >> valores[l][k];
            }
        }
    }
    void matrix::print() const {
        for (int l = 0; l < i; l++){
            for (int k = 0; k < j; k ++ ){
                std::cout << valores[l][k] << " ";
            }
            std::cout << std::endl;
        }
    };
    void matrix::swap(const int i,const int j){
        auto temp = valores[i];
        valores[i] = valores[j];
        valores[j] = temp;
    }
