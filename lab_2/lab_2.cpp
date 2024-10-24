#include <iostream>


using namespace std;

// Вариант 6.
// Написать программу, которая по полученным площади основания S (целое, 0<S<100) и
// высоте h (целое, 0<h<100), вычисляет объем пирамиды.


int main() 
{
    int S;
    int h;

    cout << "Введите площадь основания пирамиды: " << endl;
    cin >> S;
    cout << "Введите высоту пирамиды: " << endl;
    cin >> h;

    cout << (double)(S * h) / 3 << endl;
    
    return 0;
}