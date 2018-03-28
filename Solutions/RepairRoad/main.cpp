#include <bits/stdc++.h>

using namespace std;
int t, n, k;
int road[100005], pos[100005], cum[100005];
int siz = 0, ans , res;
int main()
{
    cin >> t;
    while (t--)
    {
        memset(pos, 0, sizeof pos);
        memset(cum, 0, sizeof cum);
        siz = 0;
        res = -1000000009;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> road[i];
        for (int i = 0; i < n; ++i)
            if (!road[i])
                pos[siz++] = i;
        pos[siz++] = n;
        cum[0] = pos[1];
        for (int i = 1; i < siz - 1; ++i)
            cum[i] = pos[i + 1] - pos[i - 1] - 1;
        for (int i = 1; i < siz - 1; ++i)
            cum[i] += cum[i - 1];
        res = cum[k - 1] - (pos[k -1] - pos[0] - k + 1);
        for (int i = k; i < siz - 1; ++i)
        {
            ans = cum[i] - cum[i - k] - (pos[i] - pos[i - k + 1] - k + 1);
            res = max(res, ans);
        }
        cout << res << "\n";
    }

    return 0;
}
