// http://codeforces.ru/problemset/problem/242/C
#include <set>
#include <iostream>
using namespace std;

int main()
{
    typedef set< pair<int,int> > SP;
    SP allowed;
    const int dx[8] = { -1, 0, 1, -1, 1, -1,  0,  1 };
    const int dy[8] = {  1, 1, 1,  0, 0, -1, -1, -1 };
    int x0, y0, x1, y1, n;
    cin >> x0 >> y0 >> x1 >> y1 >> n;

    for ( int i = 0; i < n; i++ ) {
        int r, a, b;
        cin >> r >> a >> b;

        for ( int j = a; j <= b; j++ ) {
            allowed.insert( make_pair( r, j ) );
        }
    }

    int s = 0, e = 0;
    int q[100000][2]; int d[100000];
    q[s][0] = x0; q[s][1] = y0; d[s] = 0;
    while ( s <= e ) {
        int cx = q[s][0], cy = q[s][1];
        if ( cx == x1 && cy == y1 ) {
            cout << d[s];
            return 0;
        }
        for ( int i = 0; i < 8; i++ ) {
            int nx = cx + dx[i], ny = cy + dy[i];
            SP::iterator it = allowed.find( make_pair( nx, ny ) );
            if ( it != allowed.end() ) {
                allowed.erase( it );
                e++;
                q[e][0] = nx; q[e][1] = ny; d[e] = d[s] + 1;
            }
        }
        s++;
    }
    cout << -1;
}
