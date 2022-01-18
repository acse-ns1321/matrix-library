#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

// Version of the lebel 1 blas operation daxpy
// which does y = a * x + y
// where x and y ar vectors and a is a scalar
void daxpy(int n, double alpha, double *dx, int incx, double *dy, int incy)
{
    for(int i =0; i < n; i++)
    dy[i * incy] += alpha *  dx[i + incx];
}

int main(){

    int size_of_vector = 500;
    double alpha = 1.5;

    auto* x_vec = new double[size_of_vector];
    auto* y_vec = new double[size_of_vector*2];

    // fill x and y vectors
    for(int i =0; i< size_of_vector; i++){
        x_vec[i] = i;
    }

    for (int i =0; i< size_of_vector*2; i++){
        y_vec[i] = i;
    }

    // compute y = alpha*

    daxpy(size_of_vector, alpha, x_vec, 1, y_vec, 2);

    for(int i = 0; i < size_of_vector * 2; i++){
        cout<< y_vec[i] << " ";
    }
    cout << endl;
    delete[] x_vec;
    delete[] y_vec;
    return 0;

}