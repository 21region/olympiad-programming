// http://codeforces.ru/problemset/problem/242/B
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int res = -1;
    int l = 0, r = 1000000000;

    vector < pair<int, int> > segments;
    map <pair<int, int>, int > ind;

    for ( int i = 0; i < n; i++ ) {
        int b[2];
        cin >> b[0] >> b[1];
        segments.push_back( pair<int, int>(b[0], b[1]) );
        ind[pair<int, int>(b[0], b[1])] = i;
    }

    sort( segments.begin(), segments.end() );

    int i = 0;
    res = 0;
    l = segments[i].first;
    r = segments[i].second;
    while ( i < segments.size() - 1 && l == segments[i + 1].first  ) {
        i++;
        if ( segments[i].second > r ) {
            res = i;
            r = segments[i].second;
        }
    }

    if ( i < segments.size() - 1 ) {
        i++;
        while ( i < segments.size() ) {
            if ( r < segments[i].second ) {
                res = -1;
                break;
            }
            i++;
        }
    }

    if (res == -1) {
        cout << res;
    } else {
        cout << ind[segments[res]] + 1;
    }
}
