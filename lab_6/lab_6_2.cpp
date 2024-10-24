#include <iostream>

using namespace std;

int main()
{
    /* Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). Упорядочить последовательность
    по неубыванию суммы цифр числа, числа с одинаковыми суммами
    цифр дополнительно упорядочить по неубыванию первой цифры числа, 
    числа с одинаковыми суммами цифр и одинаковыми первыми цифрами
    дополнительно упорядочить по неубыванию самого числа. */

    int arr[1000];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int sum_of_digits_j = 0;
            int first_digit_j = 0;
            int curr = arr[j];

            while (curr)
            {
                sum_of_digits_j += curr % 10;
                if ((curr / 10) == 0)
                {
                    first_digit_j = curr;
                }

                curr /= 10; 
            }

            int sum_of_digits_k = 0;
            int first_digit_k = 0;
            curr = arr[j + 1];

            while (curr)
            {
                sum_of_digits_k += curr % 10;
                if ((curr / 10) == 0)
                {
                    first_digit_k = curr;
                }
                curr /= 10;
            }

            if (sum_of_digits_j < sum_of_digits_k)
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            else if (sum_of_digits_j == sum_of_digits_k)
            {
                if (first_digit_j < first_digit_k)
                {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
                else if (first_digit_j == first_digit_k)
                {
                    if (arr[j] < arr[j + 1])
                    {
                        int tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                    }
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}