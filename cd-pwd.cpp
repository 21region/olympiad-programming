// http://codeforces.ru/problemset/problem/158/C
#include <string>
#include <iostream>
using namespace std;

void processAbsolutePath(string& path)
{
    size_t parentRef = path.find("..");
    while (parentRef != string::npos)
    {
        size_t slashPos = path.rfind('/', parentRef - 2);

        if (path.size() - 1 > parentRef + 1)
            path.erase(slashPos, parentRef - slashPos + 2);
        else if (slashPos != 0)
            path.erase(slashPos, parentRef - slashPos + 2);
        else
            path.erase(slashPos + 1, parentRef - slashPos + 1);

        parentRef = path.find("..");
    }
}

int main()
{
    int n;
    cin >> n;

    string currDir = "/";
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;

        if (command == "pwd")
        {
            if (currDir.size() == 1)
                cout << currDir << "\n";
            else
                cout << currDir << "/\n";
        }
        else
        {
            string path;
            cin >> path;

            if (path[0] != '/')
            {
                if (currDir.size() == 1)
                    path = "/" + path;
                else
                    path = currDir + "/" + path;
            }
            processAbsolutePath(path);
            currDir = path;
        }
    }
}
