#include "interpolacao.hpp"
#include<functional>
std::function<double(double)> converted(matrix * pontos)
{
    return [pontos](double x)
    { return lagrange(pontos, x); };
}
double trapezio(std::function<double(double)> f, double a, double b, int n){
    double integral = 0;
    double step = (b-a)/((double) n);
    for (int i = 0; i < n;i++){
        integral += (f(a + step * i) + f(a + step * (i + 1)))*step/(double) 2.0f;
    }
    return integral;
}
double simpson(std::function<double(double)> f, double a, double b, int n){
    double integral = 0;
    double step;
    if(n%2)  step = (b-a)/(((double) n+1));
    else
        step = (b - a) / (((double)n));
    for (int i = 0; i < n;i+=2){
        integral += (f(a + step * i) +4*f(a+step*(i+1)) + f(a + step * (i + 2)))*step/(double) 3.0f;
    }
    return integral;
}
double gauss_quadrature(std::function<double(double)> f, double a, double b, matrix * nodes, matrix *weigh){
    if(nodes->i != weigh->i){
        std::cout << "not enoghu weigh or nodes" << std::endl;
        exit(1);
    }
    double integral = 0;
    for (int i = 0; i < nodes->i; i++){
       // std::cout <<  f((b-a)* (nodes->valores[i][0]) / (double) 2.0f+ (b + a) / (double ) 2.0f) << "\n";
        std::cout << weigh->valores[i][0]  << std::endl;
        integral += weigh->valores[i][0] * f((b-a)* (nodes->valores[i][0]) / (double) 2.0f+ (b + a) / (double ) 2.0f)* (b-a)/((double) 2.0f);
    }
    return integral;
}