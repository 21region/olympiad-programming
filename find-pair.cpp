// http://codeforces.ru/problemset/problem/160/C
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    long long a[n];
    for (long long i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    long long first, second;
    long long i = 1, j = n;
    while (i <= n && !((n - i) * n + 1 <= k && k <= j * n))
    {
        i++; j--;
    }
    first = a[j - 1];

    int s = 0;
    int pos = 0;
    for (int m = 0; m < n; m++)
    {
        if (a[m] == first)
        {
            s++;
            if (m + 1 == j)
                pos = s;
        }
    }

    if (s == 1)
        second = a[k - (j - 1) * n - 1];
    else
    {
        int shift = k - (j - 1) * n;
        int m = (pos - 1) * n / s;
        shift += ((pos - 1) * n) % s;
        m += (shift - 1) / s;
        second = a[m];
    }
    cout << first << " " << second;
}
