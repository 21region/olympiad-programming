// http://codeforces.ru/problemset/problem/127/D
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> prefix(string s)
{
    vector<int> p(s.size());
    for (size_t i = 1; i < s.size(); i++) // i - pos of the curr symbol.
    {
        int j = p[i - 1]; // prefix of the string that ends at i - 1 symbol.
        while(j > 0 && s[j] != s[i])
            j = p[j - 1];

        p[i] = s[j] != s[i] ? 0 : j + 1;
    }
    return p;
}

int main()
{
    string s;
    cin >> s;

    vector<int> p = prefix(s);

    int l = p[p.size() - 1];
    if (l == 0)
        cout << "Just a legend";
    else
    {
        bool found = false;
        for (int i = p.size() - 2; i > 0; i--)
            if (p[i] == l)
            {
                found = true;
                break;
            }

        if (found)
            cout << s.substr(0, l);
        else
        {
            l = p[l - 1];
            if (l)
                cout << s.substr(0, l);
            else
                cout << "Just a legend";
        }
    }
}
