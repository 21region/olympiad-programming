// http://codeforces.ru/problemset/problem/120/B
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    size_t n, k;
    in >> n >> k;

    size_t numOfFirstOne = 0;

    for (size_t i = 1; i <= k; ++i)
    {
        bool a;
        in >> a;

        if (a && (numOfFirstOne == 0))
            numOfFirstOne = i;

        if (i == k)
        {
            if (a) out << k;
            else
            {
                while (!a && i < n) { in >> a; i++; }
                if (a) out << i;
                else out << numOfFirstOne;
            }
        }
    }
}
