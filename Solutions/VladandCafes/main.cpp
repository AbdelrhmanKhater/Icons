#include <bits/stdc++.h>

using namespace std;
int n, vis[1000005], cafe, t = 0;
int mx = -1000000009, res, mn = 1000000009;
int main()
{
    cin >> n;
    memset(vis, -1, sizeof vis);
    for (int i = 0; i < n; i++)
    {
        cin >> cafe;
        vis[cafe] = t++;
        mx = max(mx, cafe);
    }
    for (int i = 0; i <= mx; i++)
        if (vis[i] != -1)
        {
            if (vis[i] < mn)
            {
                mn = vis[i];
                res = i;
            }
        }
        cout << res << "\n";
    return 0;
}
