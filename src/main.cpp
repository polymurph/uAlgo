#include "main.h"
#include <iostream>

#include "../include/matrix/matrix.h"

// https://medium.com/@furkanicus/how-to-create-a-matrix-class-using-c-3641f37809c7


using namespace std;


int main()
{
    //Matrix A("A.txt");
    //Matrix B("B.txt");

    Matrix A("A.txt");
    Matrix B(3, 2);
    Matrix B_1(3, 5);
    Matrix C(3, 4, 1);
    Matrix D("B.txt");

    Matrix E(3,4,2);
    Matrix F(4,3,2);

    
    E.print();
    F.print();

    B = E * F;

    B.print();
    

    return 0;
}