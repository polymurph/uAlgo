#include "../../include/matrix/matrix.h"
#include <iostream>
#include <assert.h>

using namespace std;

Matrix::Matrix(uint32_t n) : m_rowSize(n), m_colSize(n)
{
    m_matrix.resize(n);

    for(uint32_t i = 0; i < m_matrix.size(); i++) {
        m_matrix[i].resize(n, 0);
    }
}

Matrix::Matrix(uint32_t n, double init) : m_rowSize(n), m_colSize(n)
{
    m_matrix.resize(n);

    for(uint32_t i = 0; i < m_matrix.size(); i++) {
        m_matrix[i].resize(n, init);
    }
}

Matrix::Matrix(uint32_t row, uint32_t col, double init) : m_rowSize(row), m_colSize(col)
{
    m_matrix.resize(row);

    for(uint32_t i = 0; i < m_matrix.size(); i++) {
        m_matrix[i].resize(col, init);
    }
}

Matrix::Matrix(const char * fileName)
{
    ifstream file_A(fileName); // input file stream to open the file A.txt

    // Task 1
    // Keeps track of the Column and row sizes
    int colSize = 0;
    int rowSize = 0;
    
    // read it as a vector
    string line_A;
    int idx = 0;
    double element_A;
    double *vector_A = nullptr;

    if (file_A.is_open() && file_A.good())
    {
        cout << "File "<< fileName << " is open. \n";
        while (getline(file_A, line_A))
        {
            rowSize += 1;
            stringstream stream_A(line_A);
            colSize = 0;
            while (1)
            {
                stream_A >> element_A;
                if (!stream_A)
                    break;
                colSize += 1;
                double *tempArr = new double[idx + 1];
                copy(vector_A, vector_A + idx, tempArr);
                tempArr[idx] = element_A;
                vector_A = tempArr;
                idx += 1;
            }
        }
    }
    else
    {
        cout << " WTF! failed to open. \n";
    }

    file_A.close();
    
    int j;
    idx = 0;
    m_matrix.resize(rowSize);
    for (unsigned i = 0; i < m_matrix.size(); i++) {
        m_matrix[i].resize(colSize);
    }
    for (int i = 0; i < rowSize; i++)
    {
        for (j = 0; j < colSize; j++)
        {
            this->m_matrix[i][j] = vector_A[idx];
            idx++;
        }
    }
    m_colSize = colSize;
    m_rowSize = rowSize;
    delete [] vector_A; // Tying up loose ends
    
    cout << "...done!" << endl;
}

Matrix::~Matrix()
{
    
}

void Matrix::print()
{
    uint32_t lim = m_rowSize - 1;

    cout << "[ "; 
    for(uint32_t i = 0; i < m_rowSize; i++){
        if(i > 0)cout << "  ";
        for(uint32_t j = 0; j < m_colSize; j++){
            cout << m_matrix[i][j] << " ";
        }
        if(i < lim) cout << endl;
    }
    cout << "]" << endl;
}

/*
Matrix Matrix::operator=(Matrix &A)
{
    m_rowSize =A.m_rowSize;
    m_colSize = A.m_colSize;
    m_matrix = A.m_matrix;
}
*/

Matrix Matrix::operator+(Matrix &A)
{
    cout << "Addition"<< endl;
    assert(m_colSize == A.m_colSize && m_rowSize == A.m_rowSize);
    Matrix sum(m_colSize, m_rowSize, 0);
    
    for(uint32_t i = 0; i < m_rowSize; i++){
        for(uint32_t j = 0; j < m_colSize; j++){
            sum.m_matrix[i][j] = m_matrix[i][j] + A.m_matrix[i][j];
        }
    }
    return sum;
}

Matrix Matrix::operator-(Matrix &A)
{
    cout << "Subtration"<< endl;
    assert(m_colSize == A.m_colSize && m_rowSize == A.m_rowSize);
    Matrix dif(m_colSize, m_rowSize, 0);
    
    for(uint32_t i = 0; i < m_rowSize; i++){
        for(uint32_t j = 0; j < m_colSize; j++){
            dif.m_matrix[i][j] = m_matrix[i][j] - A.m_matrix[i][j];
        }
    }
    return dif;
}

Matrix Matrix::operator*(Matrix &A)
{
    assert(m_colSize == A.m_rowSize);

    Matrix mul(m_rowSize,A.m_colSize,0);

    for(uint32_t i = 0; i < mul.m_rowSize;i++){
        for(uint32_t j = 0;j < mul.m_colSize;j++){
            for()
            A.m_matrix[][j]
        }
    }
}

// Hadamard multiplication
Matrix Matrix::operator,(Matrix &A)
{
    cout << "Hadamard Multiplication" << endl;
    assert(m_colSize == A.m_colSize && m_rowSize == A.m_rowSize);
    Matrix hmul(m_colSize, m_rowSize, 0);
    
    for(uint32_t i = 0; i < m_rowSize; i++){
        for(uint32_t j = 0; j < m_colSize; j++){
            hmul.m_matrix[i][j] = m_matrix[i][j] * A.m_matrix[i][j];
        }
    }
    return hmul;
}