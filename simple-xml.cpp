// http://codeforces.ru/problemset/problem/125/B
#include <string>
#include <iostream>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    string space = "";
    int j = 0;
    bool prevClosed = false;
    while (j < s.size()) {
        if (s[j + 1] != '/') {
            cout << space << s[j] << s[j + 1] << s[j + 2] << '\n';
            j += 3;
        }
        else {
            cout << space << s[j] << s[j + 1] << s[j + 2] << s[j + 3] << '\n';
            j += 4;
        }

        if (s[j + 1] != '/' && !prevClosed) space += "  ";
        else if (s[j + 1] == '/' && prevClosed) {
            prevClosed = true;
            space = space.erase(space.size() - 2);
        } else if (s[j + 1] == '/' && !prevClosed) {
            prevClosed = true;
        } else if (s[j + 1] != '/' && prevClosed) {
            prevClosed = false;
        }
    }
}
