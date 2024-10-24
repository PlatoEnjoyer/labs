#include <iostream>

using namespace std;


// Вариант 5.
// Установить i-ый бит числа х (0<x<10^9) в 0.

int main()
{
    int x; // 0111
    int i; // 4
    cin >> x;
    cin >> i;

    if (((1 << i) & x) == 0)
    {
        cout << "i-ый бит числа x равен нулю, программа завершена" << endl;
    }
    else
    {
        x &= ~(1 << i);
        cout << "i-ый бит числа x стал равен нулю" << endl;
        cout << "x равно: " << x << endl;
    }

    return 0;
}