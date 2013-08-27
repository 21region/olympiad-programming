// http://codeforces.ru/contest/339/problem/C
#include <vector>
#include <iostream>
using namespace std;

vector<int> rec(const vector<int>& a, vector<int> seq, int prev, int l, int r, int num, int m)
{
    int s1, s2;
    if (num % 2 == 0) { s1 = l; s2 = r; }
    else { s1 = r; s2 = l; }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != prev && a[i] + s1 > s2 ) {
            seq.push_back(a[i]);
            if (seq.size() == m) return seq;
            seq = rec(a, seq, a[i], l + (num % 2 ? 0 : a[i]), r + (num % 2 ? a[i] : 0), num + 1, m);
            if (seq.size() == m) return seq;
        }
    }
    return vector<int>();
}

int main()
{
    int m;
    string s;
    cin >> s >> m;

    vector<int> a, seq;
    for (int i = 0; i < 10; i++)
        if (s[i] == '1') a.push_back(i + 1);

    vector<int> res = rec(a, seq, -1, 0, 0, 0, m);
    if (res.empty() == false) {
        cout << "YES\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
    }
    else cout << "NO";
}
