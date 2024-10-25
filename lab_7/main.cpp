#include "functions.hpp"

/*
Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
Если в матрице есть еще один элемент, равный ее максимальному элементу, 
упорядочить строки матрицы по невозрастанию количества простых чисел среди элементов строк.
*/

int main()
{
    int n;
    int matrix[100][100];
    std::cin >> n;
    ReadData(matrix, n);
    matrix_processing(matrix, n);
    WriteData(matrix, n);

    return 0;
}