#include <bits/stdc++.h>

using namespace std;
int theta, t;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> theta;
        if (360 % (180 - theta) == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
