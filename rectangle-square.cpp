// http://codeforces.ru/contest/136/problem/D
#include <iostream>
#include <algorithm>

using namespace std;

int x[8], y[8], order[8];

int dist(int a, int b) {
    return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

bool is_rect(int a, int b, int c, int d) {
    if (x[b] - x[a] != x[c] - x[d] || y[b] - y[a] != y[c] - y[d]) return false;
    if (dist(a, b) + dist(b, c) != dist(a, c)) return false;
    return true;
}

bool is_square(int a, int b, int c, int d) {
    if (is_rect(a, b, c, d) == false) return false;
    if (dist(a, b) != dist(b, c)) return false;
    return true;
}

int main() {
    for (int i = 0; i < 8; i++) {
        cin >> x[i] >> y[i];
        order[i] = i;
    }

    bool ok = false;
    do {
        if (is_square(order[0], order[1], order[2], order[3]) &&
            is_rect(order[4], order[5], order[6], order[7])) {
            ok = true;
            break;
        }
    } while (next_permutation(order, order + 8));

    if (ok == false) cout << "NO";
    else {
        cout << "YES\n";
        for (int i = 0; i < 4; i++) cout << order[i] + 1 << " ";
        cout << "\n";
        for (int i = 4; i < 8; i++) cout << order[i] + 1 << " ";
    }
}
