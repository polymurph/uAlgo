//
//  matrix.h
//
//  Created by Furkanicus on 12/04/15.
//  Copyright (c) 2015 Furkan. All rights reserved.
// Learnrope.com

// sourc: https://medium.com/@furkanicus/how-to-create-a-matrix-class-using-c-3641f37809c7


#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdint.h>
#include <fstream> // for file access
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>

using std::vector;
using std::tuple;

class Matrix {
    public:
    Matrix(uint32_t n);
    Matrix(uint32_t n, double init);
    Matrix(uint32_t row, uint32_t col, double init);
    
    //Matrix(uint32_t rows, uint32_t cols, double);
    Matrix(const char * fileName);
    //Matrix(const Matrix &);
    ~Matrix();
    // Matrix Operations
    //Matrix operator=(Matrix&A);
    Matrix operator+(Matrix &A);
    Matrix operator-(Matrix &A);

#if 0
    // Hadamard multiplication
    Matrix operator,(Matrix &A);
#endif

    Matrix operator*(Matrix &A);
    //Matrix transpose();

    void print();

    protected:

    vector<vector<double>> m_matrix;


    private:
    uint32_t m_rowSize;
    uint32_t m_colSize;

};

#endif // _MATRIX_H_