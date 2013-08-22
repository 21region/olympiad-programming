// http://codeforces.ru/contest/257/problem/C
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    const double pi = 3.14159265358979;
    const double rad_to_deg = 180.0 / pi;

    int n; cin >> n;

    double angles[100001];
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        angles[i] = atan2(y, x);
    }

    sort(angles, angles + n);

    double view = angles[n - 1] - angles[0];
    for (int i = 1; i < n; i++)
        view = min(view, 2 * pi - (angles[i] - angles[i - 1]));

    cout.precision(10);
    cout << view * rad_to_deg;
}
