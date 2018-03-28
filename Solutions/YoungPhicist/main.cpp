#include <bits/stdc++.h>

using namespace std;
int n;
int x, y, z;
int total[3];
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        total[0] += x;
        total[1] += y;
        total[2] + z;
    }
    if (total[0] || total[1] || total[2])
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}
