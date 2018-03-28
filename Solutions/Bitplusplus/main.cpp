#include <bits/stdc++.h>

using namespace std;
int n, res = 0;
string x;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x[0] == '+' || x[2] == '+')
            res++;
        else
            res--;
    }
    cout << res << "\n";
    return 0;
}
