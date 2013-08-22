// http://codeforces.ru/problemset/problem/120/C
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ofstream out("output.txt");
    ifstream in("input.txt");

    size_t n, k;
    in >> n >> k;

    size_t pigletEatKg = 0;

    for (size_t i = 0; i < n; ++i)
    {
        size_t input;
        in >> input;

        if (input < k)
            pigletEatKg += input;
        else
        {
            if (input - k < k)
                pigletEatKg += (input - 1 * k);
            else if (input - 2 * k < k)
                pigletEatKg += (input - 2 * k);
            else
                pigletEatKg += (input - 3 * k);
        }
    }

    out << pigletEatKg;
}
