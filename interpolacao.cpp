#include "gauss.hpp"
double lagrange(matrix const *pontos,double const x){
    if(pontos->i ==1)
        return pontos->valores[0][1];
    double resposta = 0;
    double y;
    for (int i = 0; i < pontos->i;i++){
        y = pontos->valores[i][1];
        for (int j = 0; j < pontos->i;j++){
            if(i ==j){
                continue;
            }
            y *= (x - pontos->valores[j][0]) / (pontos->valores[i][0] - pontos->valores[j][0]);
        }
        resposta += y;
    }
    return resposta;
}