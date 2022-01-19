#pragma once

#include "include/Matrix.h"

template <class T>

class CSRMatrix: public Matrix<T>{

    public:

    //--- CONSTRUCTORS--------------------------------
    // Constructors that owns its own memory
    CSRMatrix(int rows, int cols, int nnzs, bool preallocate); // nnzs : the numer of non - zeros
    // Constructor that does not own its values
    CSRMatrix(int rows, int cols, int nnzs, T *values_ptr, int *row, int *cols);

    //--- DESTRUCTORS ---------------------------------
    ~CSRMatrix()

    virtual void printMatrix();

    // VARIABLE DECLARATIONS-------------------------------------
    int *row_position = nullptr;
    int *cal_index = nullptr;

    // Initialize the number of non-zeros
    int nnzs = -1;

    // Class method -----------------------------------------------
    // to multiply matrices
    // output = mat_left * this
    void matMatMult(CSRMatrix<T> &mat_left, CSRMatrix<T> &output);

    // Class method -----------------------------------------------
    // to perform a matrix vector multiplication    
    // output = this * input
    void matVecMult(T*input, T*output)

    private:

}