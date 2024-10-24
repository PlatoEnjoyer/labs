#include <iostream>
using namespace std;
 
int main()
{
    int k = 0;
    for (int i = 1; i <= 999999; ++i)
    {
        int n = i, a = 0, b = 0, q = 0;      
        while(n)
        {
            q += 1;
            if (q <= 3)
                a += n % 10;
            else 
                b += n % 10;
            n /= 10;
        }
 
        if (a == b)
            k++;
    }
 
    cout << "Количество возможных билетов = " << k << endl;

    return 0;
}