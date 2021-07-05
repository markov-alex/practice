#include <iostream>
#include <cmath>

int main()
{
    int a, b, c, d, a1, b1, c1, d1;
    int count = 0;
    std::cin >> a >> b >> c >> d;
    bool flag = true;
    while ((a != 0) && (b != 0) && (c != 0) && (d != 0))
    {
        while (flag)
        {
            if ((a == b) && (b == c) && (c == d) && (d == a))
                break;
            a1 = abs(a - b);
            b1 = abs(b - c);
            c1 = abs(c - d);
            d1 = abs(d - a);
            a = a1;
            b = b1;
            c = c1;
            d = d1;
            ++count;
        }
        std::cout << count << std::endl;
        std::cin >> a >> b >> c >> d;
        count = 0;
    }
    return 0;
}