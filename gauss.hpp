#ifndef GAUSS_H
#define GAUSS_H
#include"matrix.hpp"
#include<stack>
#include<iostream>
matrix *eliminacao(matrix &a, matrix &b);
void escalonamento(matrix &a, matrix &b, std::stack<std::pair<int, int>> swap);
//double abs(double x);
#endif