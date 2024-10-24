#include <iostream>

using namespace std;


/* Вариант 5.
1) Ввести натуральные числа A, B и C. Если A меньше B и B меньше C, то вывести C-B-A,
в противном случае если если A кратно C, то вывести A/С+B, в остальных случаях вывести A+B+C.

2) Ввести число N, обозначающее код товара в магазине. При помощи оператора switch вывести название товара. 
Код товара и название придумать самостоятельно. Минимум 5 штук. Предусмотреть обработку ошибочного ввода N.

3) Переменная x может принимать 2 значения: -1 и 1. 
Если -1, то вывести в консоль “Negative number”, если положительное - “Positive number”. 
Предложить вариант программы и объяснить свой выбор.
*/


int main()
{
    /* 1 задание Ввести натуральные числа A, B и C. Если A меньше B и B меньше C, то вывести C-B-A,
    в противном случае если если A кратно C, то вывести A/С+B, в остальных случаях вывести A+B+C.
    */
    int a;
    int b;
    int c;

    cin >> a >> b >> c;

    if (a < b && b < c) 
    {
        cout << c - b - a << endl;
    }
    else if (a % c == 0)
    {
        cout << a / c + b << endl;
    }
    else
    {
        cout << a + b + c << endl;
    }

    /*  2 задание Ввести число N, обозначающее код товара в магазине. При помощи оператора switch вывести название товара. 
    Код товара и название придумать самостоятельно. Минимум 5 штук. Предусмотреть обработку ошибочного ввода N.*/
    int n;

    cin >> n;

    switch (n)
    {
        case 1:
            cout << "Рубашка" << endl;
            break;
        
        case 2:
            cout << "Футболка" << endl;
            break;
        
        case 3:
            cout << "Джинсы" << endl;
            break;
        
        case 4:
            cout << "Блузка" << endl;
            break;
        
        case 5:
            cout << "Брюки" << endl;
            break;

        default:
            cout << "Введен некорректный номер товара" << endl;
            break;
    }

    /* 3 задание  Переменная x может принимать 2 значения: -1 и 1. 
    Если -1, то вывести в консоль “Negative number”, если положительное - “Positive number”. 
    Предложить вариант программы и объяснить свой выбор. */

    int x;

    cin >> x;

    switch (x)
    {
    case 1:
        cout << "Positive number" << endl;
        break;
    
    case -1:
        cout << "Negative number" << endl;
        break;
    
    default:
        cout << "Incorrect x" << endl;
        break;
    }

    return 0;
    
}