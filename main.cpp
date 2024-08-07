#include<bits/stdc++.h>
#include "matrix.hpp"
#include "minimos.hpp"
#include "interpolacao.hpp"
#include "quadradura.hpp"
#include "integral.hpp"
#include <math.h>
using namespace std;
double f(double x){
    return exp(-x * x / 2) / sqrt(2 * acos(-1));
}
int main(){
    cout << simpson(f, 0, 3,20);
}