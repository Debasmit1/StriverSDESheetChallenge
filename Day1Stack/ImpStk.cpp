#include <bits/stdc++.h>
using stdc++.h;

void pushStk(vector<int> &v)
{
    int x;
    cout << "Enter the num" << endl;
    cin >> x;
    v.push_back(x);
}

void topStk(vector<int> &v)
{
    cout << v[v.size() - 1] << endl;
}

void popStk(vector<int> &v)
{
    v.pop();
}

void sizeStk(vector<int> &v)
{
    cout << v.size() << " ";
}

int32_t main()
{
    vector<int> v;

    while (1)
    {
        cout << "Enter 1 to push" << endl
             << "Enter 2 to show top" << endl
             << "Enter 3 to pop" << endl
             << "Enter 4 to show size" << endl
             << "Enter -1 to exit" << endl;
        int x;
        cin >> x;
        if (x == -1)
            break;
        switch (x)
        {
        case 1:
            pushStk(v);
            break;

        case 2:
            topStk(v);
            break;

        case 3:
            popStk(v);
            break;

        case 4:
            sizeStk(v);
            break;
        }
    }

    return 0;
}