// http://codeforces.ru/contest/337/problem/D
#include <list>
#include <iostream>
using namespace std;

list<int> t[100001];
bool p[100001];
int n, m, d, dist_down[100001], dist_up[100001];

void dfs(int v)
{
    static int used[100001];
    used[v] = true;
    if (p[v] == false) dist_down[v] = -100000;
    for (list<int>::iterator i = t[v].begin(); i != t[v].end(); ++i)
        if (used[*i] == false) {
            dfs(*i);
            if (dist_down[*i] >= dist_down[v])
                dist_down[v] = dist_down[*i] + 1;
        }
}

void dfs2(int v)
{
    static int used[100001];
    used[v] = true;
    int down_max = -100000, down_max2 = -100000;
    for (list<int>::iterator i = t[v].begin(); i != t[v].end(); ++i)
        if (used[*i] == false) {
            if (dist_down[*i] > down_max) {
                down_max2 = down_max;
                down_max = dist_down[*i];
            }
            else if (dist_down[*i] > down_max2)
                down_max2 = dist_down[*i];
        }
    for (list<int>::iterator i = t[v].begin(); i != t[v].end(); ++i)
        if (used[*i] == false) {
            if (dist_up[v] >= down_max + 1)
                dist_up[*i] = dist_up[v] + 1;
            else if (dist_down[*i] < down_max || down_max == down_max2)
                dist_up[*i] = down_max + 2;
            else if (dist_down[*i] == 0 && dist_up[v] < 0 && down_max2 < 0)
                dist_up[*i] = 0;
            else if (dist_up[v] >= down_max2 + 1)
                dist_up[*i] = dist_up[v] + 1;
            else
                dist_up[*i] = down_max2 + 2;

            dfs2(*i);
        }
}

int main()
{
    cin >> n >> m >> d;
    for (int j, i = 0; i < m; i++) {
        cin >> j;
        p[j] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    dfs(1);
    if (p[1] == false) dist_up[1] = -100000;
    dfs2(1);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (dist_down[i] <= d && dist_up[i] <= d) cnt++;

    cout << cnt;
}
