// http://codeforces.ru/problemset/problem/136/E
#include <iostream>
using namespace std;

int main()
{
    char last;
    int c0 = 0, c1 = 0, cx = 0;
    while (cin >> last) {
        if (last == '0') c0++;
        else if (last == '1') c1++;
        else cx++;
    }
    if (c0 + cx > c1) cout << "00\n"; // 00[1] 0[1]0 [1]00
    if (last == '1' && c1 + cx >= c0 && c0 + cx >= c1 - 1) cout << "01\n";
    else if (last == '?' && c1 + cx >= c0 && c0 + cx - 1 >= c1) cout << "01\n";
    if (last == '0' && c1 + cx >= c0 && c0 + cx >= c1 - 1) cout << "10\n";
    else if (last == '?' && c1 + cx - 1 >= c0 + 1 && c0 + cx >= c1 - 1) cout << "10\n";
    if (c1 + cx > c0 + 1) cout << "11\n"; // 111[0] 11[0]1 1[0]11 [0]111
}
