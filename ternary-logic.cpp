// http://codeforces.ru/problemset/problem/136/B
#include <vector>
#include <iostream>

using namespace std;

int  main()
{
    long long a, b = 0, c;
    cin >> a >> c;

    int pow = 1;
    while (a != 0 || c != 0)
    {
        if ((c % 3) - (a % 3) < 0)
            b += ((c % 3) - (a % 3) + 3) * pow;
        else
            b += ((c % 3) - (a % 3)) * pow;

        a /= 3;
        c /= 3;
        pow *= 3;
    }

    cout << b;
}
