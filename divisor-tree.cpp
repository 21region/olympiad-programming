// http://codeforces.ru/problemset/problem/337/E
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll a[8], primes_cnt[8];

void build_primes()
{
    for (int i = 0; i < n; i++) {
        ll denominator = a[i];
        for (ll p = 2; p * p <= denominator; p++)
            while (denominator % p == 0) {
                primes_cnt[i]++;
                denominator /= p;
            }
        if (denominator > 1) primes_cnt[i]++;
    }
}

int dfs(int last, int nodes, int root_cnt)
{
    if (last == n) return nodes;
    if (primes_cnt[last] > 1) nodes++;

    int best = 1 << 30;
    for (int i = 0; i < last; i++) {
        if (a[i] % a[last] == 0) {
            a[i] /= a[last];
            int branch_nodes = dfs(last + 1, nodes, root_cnt);
            if (branch_nodes < best) best = branch_nodes;
            a[i] *= a[last];
        }
    }
    nodes += primes_cnt[last] > 1 ? primes_cnt[last] : 1;
    int branch_nodes = dfs(last + 1, nodes, ++root_cnt);
    if (branch_nodes < best) {
        best = branch_nodes;
        if (root_cnt == 2) best++;
    }
    return best;
}

int main()
{
    cin >> n; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);

    build_primes();
    cout << dfs(0, 0, 0);
}
