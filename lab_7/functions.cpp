#include "functions.hpp"

using namespace std;


void ReadData(int matrix[100][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void WriteData(int matrix[100][100], int n)
{
    cout << "-----------" << endl << "Результат программы:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void matrix_processing(int matrix[100][100], int n)
{
    int max_el = 0;
    int max_el_index[2] = {0, 0};
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
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
        for (int j = 0; j < n; j++)
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
            count_of_primes[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int curr = matrix[i][j];
                bool is_prime = true;
                if (curr < 2)
                {
                    is_prime = false;
                }
                else 
                {
                    for (int k = 2; k <= sqrt(curr); k++)
                    {
                    if (curr % k == 0)
                        {
                            is_prime = false;
                            break;
                        }
                    }

                }
                if (is_prime)
                {
                    count_of_primes[i] += 1;
                }
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (count_of_primes[j] > count_of_primes[j+1])
                {
                    int tmp[n];

                    for (int k = 0; k < n; k++)
                    {
                        tmp[k] = matrix[j][k];
                    }

                    for (int k = 0; k < n; k++)
                    {
                        matrix[j][k] = matrix[j + 1][k];
                    }

                    for (int k = 0; k < n; k++)
                    {
                        matrix[j + 1][k] = tmp[k];
                    }
                }
            }
        }
    }
}


