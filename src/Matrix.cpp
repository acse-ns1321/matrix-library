#include <iostream>

#include "include/Matrix.h"

template<class T>
Matrix<T>::Matrix(int rows, int cols, bool preallocate): cols(cols), rows(rows), size_of_values(rows*cols), preallocated(preallocate){
    //-----Description------------------------------------------
    // Default Constructor 1  of the class
    //----------------------------------------------------------

    // If memory is preallocated, initialize it to a new pointer
    if(this->preallocated){
        this->values = new T[size_of_values];
    }
};
template<class T>
Matrix<T>::Matrix(int rows, int cols, T *values_ptr): cols(cols), rows(rows), size_of_values(rows*cols), values(values_ptr){
    //-----Description------------------------------------------
    // Default Constructor 2  of the class
    //----------------------------------------------------------
}
template<class T>
Matrix<T>::~Matrix(){
    // ------Description-----------------------------
    // Destructor to prevent memory leaks
    //-----------------------------------------------
    if(this->preallocated){
        // only delete if we own the memory
    delete[] this->values;
    }
}

template<class T>
void Matrix<T>::printValues(){
    // ------Description-----------------------------
    // Print flattened 1-D array just as values
    //-----------------------------------------------

    std::cout << "Printing out values:" << std::endl;
    for(int i =0; i< this->size_of_values; i++){
        std::cout<<this->values[i] << " ";
    }
    std::cout<<std::endl;
}

template<class T>
void Matrix<T>::printMatrix(){
    // ----Description-----------------------------------
    // Print array values as defined but
    // in the form of a matrix
    // ---------------------------------------------------

    std::cout << "Printing out values:" << std::endl;
    // Row Major Ordering
    for(int j =0; j< this->size_of_values; j++){
        for(int i =0; i< this->size_of_values; i++){
            std::cout<<this->values[i+j*this->cols] << " ";
        }
    }
    std::cout<<std::endl;
}

template<class T>
void Matrix<T>::matMatMult(Matrix &mat_left, Matrix &output){
    // ----Description--------------------------------
    // Computes Matrix - Matrix Multiplication
    // output = mat_left * this
    //-----------------------------------------------

    // ---- Note -------------------------------------
    // Assumption is that output has correct format and
    // it has memory allocated
    // -----------------------------------------------

    // Check dimension match
    //-------------------------------------------------
    // if output(r3*c3) = mat_left(r1*c1) * this(r2*c2)
    // then c3 == c2
    // and r3 == r1 and r2 == r1
    //------------------------------------------------- 


    // For mat_left
    if (this->cols != output.cols || this->rows != mat_left.cols) 
        {
            std::cerr << "Error!!Input dimensions dont match!!!"<< std::endl;
            return;
         }
    if (mat_left.rows != output.rows){
            std::cerr << "Error!!Input dimensions dont match!!!"<< std::endl;
            return;
        }

    // Check that the output matrix has memory allocated
    if(output.values != nullptr){
        // If no memory is allcoated, allocate it explicity
        output.values = new double[mat_left.rows *this->cols];
        output.preallocated = true;
    }

    // Set values to zero before hand
    for (int i = 0; i < output.size_of_values; i++){
        output.values[i] = 0;
    }

    // Calculating Matrix-Matrix Multiplication
    for(int i = 0; i < mat_left.rows; i++){
        for(int j = 0; j < this->cols; j++){
            for(int k = 0; k < mat_left.cols; k++){
                output.values[i*this->cols + j] +=
                    mat_left.values[i * mat_left.cols +k]*
                    this->values[k * this->cols +j];
            }
        }
    }
}