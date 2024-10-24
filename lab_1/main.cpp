#include <iostream>
#include <limits>
using namespace std;

/*
Лабораторная работа №1
“Типы данных”

Дать определение переменной, понять, что это такое.
Перечислить основные типы данных в С++: целочисленные (знаковые и беззнаковые), вещественные, символьные, логические.
Указать для каждого типа размер в байтах.
Указать минимальное и максимальное значение для каждого типа.
Составить программу, которая выводит название типа, размер, мин. и макс. значения.
Привести пример выполнения арифметической операции с каждым типом данных.
Программу желательно оформить с использованием CMake и загрузить на удаленное хранилище репозиториев*.

-----
1) Переменная - это определенным образом обозначенная часть памяти
-----
2) 
Целочисленные: int, short, long, long long
Целочисленные без знака: unsigned int, unsigned short, unsigned long, unsigned long long
Вещественные: float, double, long double
Символьные: char, unsigned char
Логический - bool
----- char - 1Б                | [-1 * 2^7; 2^7 - 1]
unsigned char - 1Б       | [0; 2^8 - 1]
bool - 1Б                | [0; 1]
short - 2Б               | [-1 * 2^15; 2^15 - 1]
unsigned short - 2Б      | [0; 2^16 - 1]
float - 4Б               | [-3.4E+38; 3.4E+38]
int - 4Б                 | [-1 * 2^31; 2^31 - 1]
unsigned int - 4Б        | [0; 2^32 - 1]
long - 4Б/8Б             | [-1 * 2^31; 2^31 - 1] / [-1 * 2^63; 2^63 - 1]
unsigned long - 4Б/8Б    | [0; 2^32 - 1] / [0; 2^64 - 1]
long long - 8Б           | [-1 * 2^63; 2^63 - 1]
unsigned long long - 8Б  | [0; 2^64 - 1]
double - 8Б              | [-1.7E+308; 1.7E+308]
long double - 8Б/16Б     | [-1.7E+308; 1.7E+308] / [-1.1E+4932; 1.1E+4932]
-----
*/

int main()
{
    // 5) -----
    cout << "char                | " << sizeof(char) << "B | " << (int)numeric_limits<char>::min() << " | " <<
     (int)numeric_limits<char>::max() << endl;
    cout << "int                 | " << sizeof(int) << "B | " << numeric_limits<int>::min() << " | " <<
     numeric_limits<int>::max() << endl;
    cout << "short               | " << sizeof(short) << "B | " << numeric_limits<short>::min() << " | " <<
     numeric_limits<short>::max() << endl;
    cout << "long                | " << sizeof(long) << "B | " << numeric_limits<long>::min() << " | " <<
     numeric_limits<long>::max() << endl;
    cout << "long long           | " << sizeof(long long) << "B | " << numeric_limits<long long>::min() << " | " <<
     numeric_limits<long long>::max() << endl;
    cout << "float               | " << sizeof(float) << "B | " << numeric_limits<float>::min() << " | " << 
    numeric_limits<float>::max() << endl;
    cout << "double              | " << sizeof(double) << "B | " << numeric_limits<double>::min() << " | " <<
     numeric_limits<double>::max() << endl;
    cout << "long double         | " << sizeof(long double) << "B | " << numeric_limits<long double>::min() << " | " <<
     numeric_limits<long double>::max() << endl;

    cout << "unsigned char       | " << sizeof(unsigned char) << "B | " << (int)numeric_limits<unsigned char>::min() << " | " <<
     (int)numeric_limits<unsigned char>::max() << endl;
    cout << "unsigned int        | " << sizeof(unsigned int) << "B | " << numeric_limits<unsigned int>::min() << " | " <<
     numeric_limits<unsigned int>::max() << endl;
    cout << "unsigned short      | " << sizeof(unsigned short) << "B | " << numeric_limits<unsigned short>::min() << " | " <<
     numeric_limits<unsigned short>::max() << endl;
    cout << "unsigned long       | " << sizeof(unsigned long) << "B | " << numeric_limits<unsigned long>::min() << " | " <<
     numeric_limits<unsigned long>::max() << endl;
    cout << "unsigned long long  | " << sizeof(unsigned long long) << "B | " << numeric_limits<unsigned long long>::min() << " | " <<
     numeric_limits<unsigned long long>::max() << endl;

    cout << "bool                | " << sizeof(bool) << "B |" << " 0" << " | " << "1" << endl; 
    
    // 6) -----

    cout << endl << endl;

    char a_c = 96, b_c = 101;
    cout << "char: " << a_c << " + " << b_c << " = " << (char)(a_c + b_c) << endl;

    int a_i = 1, b_i = 2;
    cout << "int: " << a_i << " + " << b_i << " = " << (a_i + b_i) << endl;

    short a_s = 1, b_s = 2;
    cout << "short: " << a_s << " + " << b_s << " = " << (a_s + b_s) << endl;

    long a_l = 1, b_l = 2;
    cout << "long: " << a_l << " + " << b_l << " = " << (a_l + b_l) << endl;

    long long a_ll = 1, b_ll = 2;
    cout << "long long: " << a_ll << " + " << b_ll << " = " << (a_ll + b_ll) << endl;

    float a_f = 1.0f, b_f = 2.0f;
    cout << "float: " << a_f << " + " << b_f << " = " << (a_f + b_f) << endl;

    double a_d = 1.0, b_d = 2.0;
    cout << "double: " << a_d << " + " << b_d << " = " << (a_d + b_d) << endl;

    long double a_ld = 1.0, b_ld = 2.0;
    cout << "long double: " << a_ld << " + " << b_ld << " = " << (a_ld + b_ld) << endl;

    unsigned char a_uc = 1, b_uc = 2;
    cout << "unsigned char: " << a_uc << " + " << b_uc << " = " << (a_uc + b_uc) << endl;

    unsigned int a_ui = 1, b_ui = 2;
    cout << "unsigned int: " << a_ui << " + " << b_ui << " = " << (a_ui + b_ui) << endl;

    unsigned short a_us = 1, b_us = 2;
    cout << "unsigned short: " << a_us << " + " << b_us << " = " << (a_us + b_us) << endl;

    unsigned long a_ul = 1, b_ul = 2;
    cout << "unsigned long: " << a_ul << " + " << b_ul << " = " << (a_ul + b_ul) << endl;

    unsigned long long a_ull = 1, b_ull = 2;
    cout << "unsigned long long: " << a_ull << " + " << b_ull << " = " << (a_ull + b_ull) << endl;

    return 0;
}