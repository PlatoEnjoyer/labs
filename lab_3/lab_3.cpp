#include <iostream>

using namespace std;

int main()
{
    int i = 312;
    int c;

    while (i > 0)
    {
        c = i % 2;
        cout << c;
        i = i / 2;
    }
    
}