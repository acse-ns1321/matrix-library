#pragma once

template<class T>

class Matrix {

    // A CLASS THAT DEFINES A MATRIX AND ITS OPERATIONS

    public:
    // ----First Default Constructor ----------------------------  
    // A Contructor to create a Matrix when the class is called
    // this will be when the library wull  preallocate memory 
    Matrix(int rows, int cols, bool preallocate);

    // ----Second Default Constructor ----------------------------  
    // this constructor is called when we have allocated
    // memory outside
    Matrix(int rows, int cols, T *value_ptr);

    // The Class Destructor ---------------------------------------
    // that is invoked vvirtually by every instance of the class
    virtual ~Matrix();

    // Class method -----------------------------------------------
    // to print out the matrix
    void printMatrix();

    // Class method -----------------------------------------------
    // to print values of the matrix withour formatting
    void printValues();

    // Class method -----------------------------------------------
    // to multiply matrices
    // output = mat_left * this
    void matMatMult(Matrix<T> &mat_left, Matrix<T> &output);

    // Initialize Class Variables ---------------------------------
    // rows and columns to be publicly accessed 
    // ---- Note --------------------------------------------------
    // Numerics library gives access to users to improve speed
    // ------------------------------------------------------------
    int rows = -1;
    int cols = -1;

    // Initialize null pointer for the values
    // ---- Note --------------------------------------------------
    // If not public, the speed reduces dramatically
    // i.e. its expensive!
    // This is defined as Row Major Ordering
    // -------------------------------------------------------------
    T* values = NULL;

    // Accessible by a subclass/child class
    protected:
    // If values pointer is set or not
    bool preallocated = false;
    int size_of_values = -1;

    private:
    // ---- Note ----------------------------------------------------
    // You shouldn't be able to resize matrices 
    // This is because even in resizing, a new matrix is created and 
    // the old one is copied. However this happens in the background
    // so the user assumes the resizing is slow, when infact the 
    // whole matrix is being created and copied again!
    // ---------------------------------------------------------------
    // int size_of_values = -1;//chnaged to proetced when creating CSR child class


};