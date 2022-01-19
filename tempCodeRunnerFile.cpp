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
