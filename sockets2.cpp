// http://codeforces.ru/contest/257/problem/A
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[50];
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    reverse(a, a + n);

    int r = m - k, used = 0;
    while (r > 0 && used < n) {
        r -= a[used] - 1;
        used++;
    }
    cout << (r > 0 ? -1 : used);
}
