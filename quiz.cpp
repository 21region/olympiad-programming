// http://codeforces.ru/contest/337/problem/C
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll powmod(ll a, ll n, ll m)
{
    ll res = 1;
    for (; n; n >>= 1) {
        if (n & 1) {
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
    }
    return res;
}

int main()
{
    const ll prime = 1000 * 1000 * 1000 + 9;

    ll n, m, k;
    cin >> n >> m >> k;

    ll bound = n / k * (k - 1) + n % k;
    if (m <= bound) {
        cout << m;
    } else {
        ll s = m - bound;
        ll r = bound - s * (k - 1);
        ll score = (k % prime) * (powmod(2, s + 1, prime) - 2) + prime;
        cout << (score % prime + r) % prime;
    }
}
