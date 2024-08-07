#ifndef matrix1
#define matrix1
#include <cstdlib>
#include <iostream>
class matrix{
    public:
        int i;
        int j;
        double **valores;
        matrix(const int i, const int j);
        matrix() = delete;
        ~matrix();
        matrix(const matrix &other);
        matrix &operator=(const matrix &other);
        matrix(matrix &&other);
        matrix &operator=(matrix &&other);
        double get(const int i,const int j) const;
        void set(const int i, const int j, const double value);
        matrix *transposta() const;
        matrix *operator*(const matrix &other) const;
        matrix *operator+(const matrix &other) const;
        matrix *operator-(const matrix &other) const;
        bool valid(const int i, const int j) const;
        void read_matrix();
        void print() const;
        void swap(const int i,const int j);
};
#endif