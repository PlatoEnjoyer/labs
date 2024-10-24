#include <iostream>
#include <cmath>

using namespace std;

// Вариант 5

int main()
{
    // 1) Дана последовательность вещественных чисел {Aj}. Найти произведение отрицательных чисел
    // с ненулевой дробной частью, наименьшее из таких чисел и номер этого числа в последовательности.

    int number_of_elements;
    double multiply = 1;
    double min_digit = 0;
    int min_digit_number = -1;

    cout << "Введите количество членов последовательности" << endl;
    cin >> number_of_elements;

    for (int i = 0; i < number_of_elements; i++ )
    {
        double curr;
        cin >> curr;

        if (curr - (int)curr != 0)
        {
            if (curr < min_digit)
            {
                min_digit = curr;
                min_digit_number = i;
            }
            multiply = multiply * curr;
        } 
    }

    if (min_digit == 0)
    {
        cout << " Провал " << endl;
    }
    else
    {
    cout << "Произведение = " << multiply << endl;
    cout << "Минимальное число: " << min_digit << endl;
    cout << "Индекс минимального числа: " << min_digit_number << endl;
    }


    


    // 2) Дано натуральное число N (N<10^9). Найти наименьшую цифру числа N.

    unsigned int n;
    unsigned int min = 9;
    cout << "Введите число" << endl;
    cin >> n;

    while(n)
    {
        if (min > n % 10)
        {
            min = n % 10;
        }

        n = n / 10;
    }

    cout << "Минимальная цифра числа: " << min << endl;
    return 0;
}