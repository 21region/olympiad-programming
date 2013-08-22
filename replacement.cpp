// http://codeforces.ru/problemset/problem/136/C
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int  main()
{
    int n;
    cin >> n;

    bool special = true;
    int arr[n];
    int copy[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        copy[i] = arr[i];

        if (arr[i] != 1) special = false;
    }

    sort(arr, arr + n);

    if (n == 1 && arr[0] == 1) cout << 2;
    else if (n == 1) cout << 1;
    else
    {
        cout << 1 << ' ';

        if (special)
        {
            for (int i = 1; i < n - 1; i++)
                cout << 1 << ' ';

            cout << 2;
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                cout << arr[i - 1] << ' ';
            }
        }
    }
}
