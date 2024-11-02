#include <iostream>



/*
Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). 
Удалить из последовательности числа, произведение цифр которых кратно 18, а среди оставшихся продублировать числа, 
содержащие цифру 7, но не содержащие цифру 0.
*/
bool is_multi_of_18(int a)
{
    int multi = 1;

    while (a)
    {
        int curr = a % 10;
        multi = multi * curr;
        a %= 10;
    }

    return bool(multi % 18 == 0);
}

bool is_contain_7_non_contain_0 (int a)
{
    bool contain_7 = false;

    while (a)
    {
        int curr = a % 10;
        if (curr == 0)
        {
            return false;
        }
        else
        {
            if (curr == 7)
            {
                contain_7 = true;
            }
        }
    }

    return contain_7;
}



int main()
{
    int n;
    int arr[10000];

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (is_multi_of_18(arr[i]))
        {
            int j = i;
            while (j < n)   
            {
                arr[j] = arr[j + 1];
                n--;
                i--;
                j += 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}