#include <iostream>
#include <cmath>




int main()
{
    int a = 1000;
    int b = 1000;
    int ans = 0;
    int x1;
    int y1;
    int r1;
    int x2;
    int y2;
    int r2;

    int x;
    int y;
    int cnt;
    int n = 10;

    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    int circle[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            circle[i][j] = 0;
        }
    }

    circle[x1 + r1][y1] = 1;
    circle[x1 - r1][y1] = 1;
    circle[x1][y1 + r1] = 1;
    circle[x1][y1 - r1] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << circle[i][j];
        }
        std::cout << std::endl;
    }
}