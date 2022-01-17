#include <iostream>
# include "include/Matrix.h"


Matrix::Matrix(int rows, int cols, bool preallocate): cols(cols), rows(rows), size_of_values(rows*cols), preallocated(preallocate){
    //-----Description------------------------------------------
    // Default Constructor 1  of the class
    //----------------------------------------------------------

    // If memory is preallocated, initialize it to a new pointer
    if(this->preallocated){
        this.values = new double[this->size_of_values];
    }
}

Matrix::Matrix(int rows, int cols, double *values_ptr): cols(cols), rows(rows), size_of_values(rows*cols), values(values_ptr){
    //-----Description------------------------------------------
    // Default Constructor 2  of the class
    //----------------------------------------------------------
}

Matrix::~Matrix(){
    // ------Description-----------------------------
    // Destructor to prevent memory leaks
    //-----------------------------------------------
    if(this->preallocated){
        // only delete if we own the memory
    delete[] this->values;
    }
}

void Matrix::printValues(){
    // ------Description-----------------------------
    // Print flattened array just as values
    //-----------------------------------------------

    std::cout << "Printing out values:" << std::endl;
    for(int i =0; i< this->size_of_values; i++){
        std::cout<<this->values[i] << " ";
    }
    std::cout<<std::endl;
}

void Matrix::printMatrix(){
    // ----Description-----------------------------------
    // Print array values just as defined 
    // in the form of a matrix
    // ---------------------------------------------------

    std::cout << "Printing out values:" << std::endl;
    // Row Major Ordering
    for(int j =0; i< this->size_of_values; j++){
        for(int i =0; i< this->size_of_values; i++){
            std::cout<<this->values[i+j*this->cols] << " ";
        }
    }
    std::cout<<std::endl;
}

void Matrix::matMatMult(Matrix &mat_left, Matrix &output){
    // ----Description--------------------------------
    // Computes Matrix - Matrix Multiplication
    // output = mat_left * output
    //-----------------------------------------------

    // ---- Note -------------------------------------
    // Assumption is that output has correct format and
    // it has memory allocated
    // -----------------------------------------------

    // Check dimension match
    //-----
    //
    //-----
    if (this->rows||
        this->cols||
        ||){

        }

    // Check that the output matrix has memory allocated
    if(output.values != nullptr){
        // If no memory is allcoated, allocate it explicity
        output.values = new double[mat_left.rows *this.cols];
        output.preallocated = true;
    }

    // Calculating Matrix-Matrix Multiplication
    for(int i = 0; i < this->rows; i++){
        for(int k = 0; k < this->cols; k++){
            for(int j = 0; j < mat_left.cols; j++){
                output.values[i*output.cols + j] +=
                    this->values[i * this->]*
                    mat_left.values[k * mat_left.cols +j]
            }
        }
    }
}