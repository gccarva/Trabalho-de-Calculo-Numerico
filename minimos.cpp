#include "gauss.hpp"
matrix *minimos(matrix *a, matrix *b){
    //if(grau > npontos-1 || grau < 0){
    //    std::cout << "num de pontos tem que ser maior que grau" << std::endl;
    //    exit(1);
    //}
    if(a->i == a->j){
        return eliminacao(*a, *b);
    }
    matrix *transposta = a->transposta();
    matrix *na = (*transposta) * (*a);
    matrix *nb = (*transposta) * (*b);
    delete transposta;
    matrix *xl = eliminacao(*na, *nb);
    delete na;
    delete nb;
    return xl;
}