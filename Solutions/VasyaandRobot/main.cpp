#include <bits/stdc++.h>

using namespace std;
int cum[100005];
int s, e, l, r;
int qr, ql;
int n;
int res = 2147483647, ans;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> l >> r >> ql >> qr;
    for (int i = 1; i <= n; ++i)
        cin >> cum[i];
    for (int i = 1; i <= n; ++i)
        cum[i] += cum[i - 1];

    for (int i = 0; i <= n; ++i)
    {
        ans = cum[i] * l + (cum[n] - cum[i]) * r;
        if (i > n - i)
            ans = ans + (2 * i - n - 1) * ql;
        else if (i < n - i)
            ans = ans + (n - 2 * i - 1) * qr;
        res = min(res, ans);
    }
    cout << res << "\n";
    return 0;
}
