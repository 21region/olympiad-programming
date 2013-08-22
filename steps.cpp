// http://codeforces.ru/problemset/problem/152/B
#include <string>
#include <iostream>

using namespace std;

struct vec
{
    long long dx, dy;
};

int main()
{
    long long n, m;
    long long x, y;
    long long k;
    cin >> n >> m >> x >> y >> k;

    vec v[k];
    for (int i = 0; i < k; i++)
        cin >> v[i].dx >> v[i].dy;

    long long totalSteps = 0;
    for (long long i = 0; i < k; i++)
    {
        long long dx = n - x;
        long long dy = m - y;

        bool forbidden = false;

        long long stepX = 0, stepY = 0;
        if (v[i].dx > 0)
        {
            stepX = dx / v[i].dx;
            if (!stepX)
                forbidden = true;
        }
        else if (v[i].dx < 0)
        {
            stepX = -(x - 1) / v[i].dx;
            if (!stepX)
                forbidden = true;
        }
        if (v[i].dy > 0)
        {
            stepY = dy / v[i].dy;
            if (!stepY)
                forbidden = true;
        }
        else if (v[i].dy < 0)
        {
            stepY = -(y - 1) / v[i].dy;
            if (!stepY)
                forbidden = true;
        }

        if (!forbidden)
        {
            long long step;
            if (stepX && stepY)
                step = min(stepX, stepY);
            else if (stepX)
                step = stepX;
            else
                step = stepY;

            totalSteps += step;

            x += step * v[i].dx;
            y += step * v[i].dy;
        }
    }
    cout << totalSteps;
}
