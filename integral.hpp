#ifndef INTEGRAL_H
#define INTEGRAL_H
#include "interpolacao.hpp"
#include<functional>
std::function<double(double)> converted(matrix *pontos);
double trapezio(std::function<double(double)> f, double a, double b, int n);
double simpson(std::function<double(double)> f, double a, double b, int n);
double gauss_quadrature(std::function<double(double)> f, double a, double b, matrix * nodes, matrix *weigh);
#endif