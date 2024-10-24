#include <iostream>

using namespace std;

int main()
{
    /* Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). 
    Если в последовательности нет чисел с суммой цифр, равной 19, 
    упорядочить последовательность по невозрастанию. */

    int num_of_elements;
    cin >> num_of_elements;
    int arr[10000];
    bool flag = true;

    for (int i; i < num_of_elements; i++)
    {
        cin >> arr[i];
        int curr = arr[i];
        int sum_of_digits = 0;

        while (curr)
        {
            sum_of_digits += curr % 10;
            curr /= 10;
        }

        if (sum_of_digits == 19)
        {
            flag = false;
        }
    }

    if (flag)
    {
        for (int i = 0; i < num_of_elements - 1; i++)
        {
            for (int j = 0; j < num_of_elements - i - 1; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
    }

    for (int i = 0; i < num_of_elements; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;

}