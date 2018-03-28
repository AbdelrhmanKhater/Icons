#include <bits/stdc++.h>

using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    if (n == 1 && k != 10)
        cout << k << "\n";
    else if (n == 1 && k == 10)
         cout << -1 << "\n";
    else if (k == 10)
    {
        for (int i = 0; i < n - 1; i++)
            cout << "1";
        cout << "0\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << k;
        cout << "\n";
    }
    return 0;
}
