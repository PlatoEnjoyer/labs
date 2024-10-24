#include <iostream>

using namespace std;

int main()
{
    /* Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000).
    Удалить из последовательности числа, начинающиеся и заканчивающиеся одной и той же цифрой, 
    а среди оставшихся продублировать числа, начинающиеся цифрой 3. */

    int A[20000];
    int n;
    cin >> n;
    int shift = 0;

    for (int i = 0; i < n; i++)
    {   

        cin >> A[i - shift];
        int first_digit = 0;
        int last_digit = A[i - shift] % 10;
        int curr = A[i - shift];

        while (curr)
        {
            if ((curr % 10) == curr)
            {
                first_digit = curr;
            }
            curr /= 10;
        }

        if (last_digit == first_digit)
        {
            A[i - shift] = 0;
            if (A[i - shift] != 0)
            {
                shift += 1;
            }
            else
            {
                shift += 1;
                n--;
            }
            
        }
    }

    n -= shift;
    
    for (int i = 0; i < n; i++)
    {
        int curr = A[i];
        int first_digit = 0;

        while (curr)
        {
            if ((curr % 10) == curr)
            {
                first_digit = curr;
            }
            curr /= 10;
        }

        if (first_digit == 3)
        {
            for (int j = n; j > i; j--)
            {
                A[j] = A[j - 1];
            }
            n++;
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }



    cout << endl;

    return 0;
}