#include <iostream>
#include <math.h>
#include <ctime>

#include "include/Matrix.h"

using namespace std;

int main(){

    // Initialize rows and columns
    int rows = 5;
    int columns = 5;

    // ----- Case 1 -----------------------------------------
    // Let the matrix allocate its own memory addresss
    //-------------------------------------------------------
    auto *dense_mat = new Matrix(rows, cols, true);

    for(int i; i < rows*cols; i++){
        dense_mat.values[i] = i;
    }
    dense_mat->printValues();
    dense_mat->printMatrix();

    delete dense_mat;

    // ----- Case 2 -----------------------------------------
    //  the library allocates the pointer to the memeory
    //-------------------------------------------------------
    
    }