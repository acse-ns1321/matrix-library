#include <iostream>
#include <math.h>
#include <ctime>

#include "include/Matrix.h"

using namespace std;

int main(){

    // Initialize rows and columns
    int rows = 5;
    int cols = 5;

    // ----- Case 1 -----------------------------------------
    // Let the matrix allocate its own memory addresss
    //-------------------------------------------------------
    auto *dense_mat = new Matrix(rows, cols, true);

    // Fill matrix with random values for now
    for(int i; i < rows*cols; i++){
        dense_mat.values[i] = i;
    }

    // Print matrix values and the whole matrix
    dense_mat->printValues();
    dense_mat->printMatrix();

    delete dense_mat;

    // ----- Case 2 -----------------------------------------
    //  the library allocates the pointer to the memeory
    //-------------------------------------------------------
    
    // Allocate the pointer to the memory of the matrix
    auto *matrix_data = new double[rows*cols];
    dense_mat = new Matrix(rows, cols, matrix_data); 
    
    // -- Note ----
    // Dense_mat inputs the adress of the pointer we created
    // ------------

    // Fill in usiing matrix_data pointer, that points
    // to the same location as dense_mat->values
     for(int i =0; i< rows*cols; i++){
         matrix_data[i] = i;
     }

    // Print matrix values and the whole matrix
    dense_mat->printValues();
    dense_mat->printMatrix();

    // -----------------------------------------------------
    //  Testig the Matmul Operation
    //-------------------------------------------------------
    
    // Allocating memry to the pointers of the matmul matrices
    auto *left_mat = new Matrix(rows, cols, matrix_data);
    auto *output_mat = new Matrix(rows, cols, true);

    // Call the matmul routine and time it
    clock_t start = clock();
    dense_mat->matMatMult()(*left_mat, *output_mat);
    clock_t end = clock();

    // Print the time taken
    cout << "Time - Spent : "<< (double)(end - start)/(double)(CLOCKS_PER_SEC)*1000.0 << endl;

     // Explicity delete memory of array
     delete[] matrix_data;
    // Explicitly delete memory used by matrix object
    delete matrix_data;
    delete left_mat;
    delete output_mat;
    }