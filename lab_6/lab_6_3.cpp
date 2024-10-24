#include <iostream>

using namespace std;

int main()
{
        /* Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
    Найти строку с наибольшей по абсолютной величине суммой элементов и заменить все элементы этой строки числом 9999. */
    
    int A[100][100];
    int n;
    int m;
    int max_i = 0;
    int max_sum = 0;

    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        int sum_i = 0;

        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
            //sum_i+=abs(A[i][j]);
            if (A[i][j] > 0)
            {
                sum_i += A[i][j];
            }
            else
            {
                sum_i -= A[i][j];
            }
            
        }

        if (sum_i > max_sum)
        {
            max_sum = sum_i;
            max_i = i;
        }
    }

    for (int j = 0; j < m; j++)
    {
        A[max_i][j] = 9999;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}