// http://codeforces.ru/problemset/problem/144/C
#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    char s[100001];

    while (true)
    {
        cin.get(s[n]);
        if (s[n] == '\n')
            break;
        n++;
    }

    int m = 0;
    int p[26] = {};
    while (true)
    {
        int i = cin.get() - 'a';
        if (i >= 0)
        {
            m++;
            p[i]++;
        }
        else
            break;
    }

    int curr[26] = {};
    for (int i = 0; i < m; i++)
        if (s[i] != '?')
            curr[s[i] - 'a']++;

    int good = 0;
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < 26 && p[j] >= curr[j]) j++;
        if (j == 26)
            good++;

        if(s[i] != '?')
            curr[s[i] - 'a']--;
        if(s[i + m] != '?')
            curr[s[i + m] - 'a']++;
    }

    cout << good;
}
