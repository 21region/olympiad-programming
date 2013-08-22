// http://codeforces.ru/problemset/problem/159/C#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int k, n;
    string s;
    cin >> k >> s >> n;

    vector<int> m[26];
    for (int i = 0; i < k; i++)
        for (int j = 0; j < s.size(); j++)
            m[s[j] - 'a'].push_back(j + i * s.size());

    for (int i = 0; i < n; i++)
    {
        int p;
        char c;
        cin >> p >> c;
        c -= 'a';

        m[c].erase(m[c].begin() + p - 1);
    }

    string t(k * s.size(), ' ');
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < m[i].size(); j++)
            t[m[i][j]] = char(i + 'a');

    for (int i = 0; i < t.size(); i++)
        if (t[i] != ' ')
            cout << t[i];
}
