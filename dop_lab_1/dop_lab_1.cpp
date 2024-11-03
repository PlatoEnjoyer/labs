#include <iostream>
#include <cmath>

/*
 Судоходная компания предлагает два вида транспорта для перевозки сыпучих грузов. 
 Грузовик первого типа может перевезти Q1 тонн груза за одну поездку.
 Разовая поездка стоит P1, и цена не зависит от уровня загрузки транспортного средства. 
 Для грузовика второго типа эти значения равны Q2 и P2 соответственно.
 Найдите минимальную стоимость перевозки A тонн груза.
*/

int main()
{
    int q1;
    int p1;
    int q2;
    int p2;
    int a;
    int ans = 0;

    std::cin >> q1 >> p1 >> q2 >> p2 >> a;

    float value1 = (float)p1/q1;
    float value2 = (float)p2/q2;

    while (a > 0)
    {
        if (value1 < value2 or (value1 == value2 && q1 < q2))
        {
            if (a < q2 && p1 > p2)
            {
                ans += p2;
                break;
            }
            a -= q1;
            ans += p1;
        }
        else
        {
            if (a < q1 && p2 > p1)
            {
                ans += p1;
                break;
            }
            a -= q2;
            ans += p2;            
        }
    }

    std::cout << ans << std::endl;

    return 0;

}