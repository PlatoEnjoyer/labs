#include <iostream>


using namespace std;

int main() 
{
    int S;
    int h;

    cout << "Введите площадь основания пирамиды: " << endl;
    cin >> S;
    cout << "Введите высоту пирамиды: " << endl;
    cin >> h;

    cout << (float)(S * h) / 3 << endl;

}