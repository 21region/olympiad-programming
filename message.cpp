// http://codeforces.ru/problemset/problem/157/C
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    bool quit = false;
    int longestLength = 0;
    int longestIndexS = -1;
    int longestIndexT = -1;
    for (int i = 0; i < t.size() && !quit; i++)
    {
        size_t pos = s.find(t[i]);
        while (pos != string::npos && !quit)
        {
            int length = 1;
            for (int j = i + 1, k = pos + 1; j < t.size() && k < s.size(); j++, k++)
                if (s[k] == t[j])
                    length++;

            if (length > longestLength)
            {
                longestIndexT = i;
                longestIndexS = pos;
                longestLength = length;
            }
            pos = s.find(t[i], pos + 1);

            if (t.size() - i <= longestLength) quit = true; // would it help?
        }
    }

    if (longestIndexS == -1)
        cout << t.size();
    else
    {
        int totalAdded = longestIndexT;
        int j = longestIndexT;
        for (int i = longestIndexS; i < s.size() && j < t.size(); i++, j++)
        {
            if (s[i] != t[j])
                totalAdded++;
        }

        if (t.size() - j > 0)
            totalAdded += t.size() - j;

        cout << totalAdded;
    }
}
