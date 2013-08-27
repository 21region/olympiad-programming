// http://codeforces.ru/contest/339/problem/D
#include <iostream>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    int c = 1 << n; int tree[1 << 18];
    for (int i = 0; i < c; i++) cin >> tree[i];
    for (int l = 0, s = c; l < n; l++, s /= 2, c += s)
        for (int i = 0; i < s; i += 2)
            tree[i / 2 + c] = l & 1 ? tree[c - s + i] ^ tree[c - s + i + 1]:
                                      tree[c - s + i] | tree[c - s + i + 1];
    for (int i = 0, p, b; i < m; i++) {
        cin >> p >> b;
        tree[--p] = b;
        for (int l = 0, c = 1 << n, s = c; l < n; l++, p /= 2, s /= 2, c += s) {
            if (p & 1) p--;
            tree[p / 2 + c] = l & 1 ? tree[c - s + p] ^ tree[c - s + p + 1]:
                                      tree[c - s + p] | tree[c - s + p + 1];
        } cout << tree[(1 << (n + 1)) - 2] << '\n';
    }
}
