#include <iostream>
#include <cmath>

using namespace std;


/*
Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
Если в матрице есть еще один элемент, равный ее максимальному элементу, 
упорядочить строки матрицы по невозрастанию количества простых чисел среди элементов строк.
*/
int main()
{
    int n;
    int m;
    int matrix[100][100];
    int max_el = 0;
    int max_el_index[2] = {0, 0};
    bool flag = false;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] >= max_el)
            {   
                max_el_index[0] = i;
                max_el_index[1] = j; 
                max_el = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (flag)
        {
            break;
        }
        for (int j = 0; j < m; j++)
        {
            if ((matrix[i][j] == max_el) && (i != max_el_index[0] || j != max_el_index[1]))
            {
                flag = true;
                break;
            }
        }
    }

    if (flag)
    {
        int count_of_primes[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int curr = matrix[i][j];
                bool is_prime = true;
                for (int k = 2; k <= sqrt(curr); k++)
                {
                    if (curr % k == 0)
                    {
                        is_prime = false;
                        break;
                    }
                }
                if (is_prime)
                {
                    count_of_primes[i] += 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                if (count_of_primes[i] > count_of_primes[j])
                {
                    int tmp[m];

                    for (int k = 0; k < m; k++)
                    {
                        tmp[k] = matrix[j][k];
                    }

                    for (int k = 0; k < m; k++)
                    {
                        matrix[j][k] = matrix[j + 1][k];
                    }

                    for (int k = 0; k < m; k++)
                    {
                        matrix[j + 1][k] = tmp[k];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
    
}


