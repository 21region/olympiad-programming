// http://codeforces.ru/contest/257/problem/A
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int a[51] = { 0 };
    for (int i = 0; i < n; i++) {
        int a_i;
        cin >> a_i;
        a[a_i]++;
    }

    int max = 50;
    int count = 0;
    while ( m > k ) {
        while ( a[max] == 0 ) {
            max--;
            if ( max <= 1 ) {
                cout << -1;
                return 0;
            }
        }
        k--;
        k += max;
        count++;
        a[max]--;
    }
    cout << count;
}
