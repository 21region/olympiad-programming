// http://codeforces.ru/problemset/problem/242/D
#include <list>
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    list<int> g[100001];
    for ( int i = 1; i <= m; i++ ) {
        int u, v;
        cin >> u >> v;
        g[u].push_back( v );
        g[v].push_back( u );
    }

    int a[100001];
    for ( int i = 1; i <= n; i++ ) {
        int val;
        cin >> val;
        a[i] = val;
    }

    list<int> q;
    int c[100001] = { 0 };
    for ( int i = 1; i <= n; i++ ) {
        if ( c[i] == a[i] ) {
            q.push_back( i );
        }
    }

    list<int> k;
    while ( !q.empty() ) {
        int v = q.front();
        q.pop_front();

        if ( c[v] == a[v] ) {
            c[v]++;
            k.push_back( v );
            list<int>::iterator it = g[v].begin();
            while ( it != g[v].end() ) {
                if ( ++c[*it] == a[*it] ) {
                    q.push_back( *it );
                }
                ++it;
            }
        }
    }
    cout << k.size() << "\n";
    list<int>::iterator it = k.begin();
    while ( it != k.end() ) {
        cout << *it << " ";
        ++it;
    }
}
