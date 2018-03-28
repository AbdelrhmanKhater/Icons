#include <bits/stdc++.h>

using namespace std;
int cum[1000005];
int t, n, cnt;
long long res;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        res = 0;
        cin >> cum[0];
        res += !cum[0];
        for (int i = 1; i < n; ++i)
        {
            cin >> cum[i];
            cum[i] += cum[i - 1];
            res += !cum[i];
        }
        sort(cum, cum + n);
        cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (cum[i] == cum[i - 1])
                ++cnt;
            else
            {
                res += 1ll * cnt * (cnt - 1) / 2ll;
                cnt = 1;
            }
        }
        res += 1ll * cnt * (cnt - 1) / 2ll;
        cout << res << "\n";
    }
    return 0;
}
