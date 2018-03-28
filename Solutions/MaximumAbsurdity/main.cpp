#include <bits/stdc++.h>

using namespace std;
long long cum[200010], cur, ans;
pair<long long, long long> mx, res;
int n, k;
long long Cumulative_Solve(int s, int e)
{
    return cum[e] - cum[s - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> cum[i];
        cum[i] += cum[i - 1];
    }
    res = make_pair(n - 2 * k + 1, n - k + 1);
    mx = make_pair(n - k + 1, Cumulative_Solve(n - k + 1, n));
    ans = Cumulative_Solve(n - k + 1, n) + Cumulative_Solve(n - 2 * k + 1, n - k);
    for (int i = n - 2 * k; i >= 1; --i)
    {
        cur = Cumulative_Solve(i + k, i + 2 * k - 1);
        if (cur >= mx.second)
            mx = make_pair(i + k, cur);
        cur = Cumulative_Solve(i, i + k - 1) + mx.second;
        if (cur >= ans)
        {
            ans = cur;
            res = make_pair(i, mx.first);
        }
    }
    cout << res.first << " " << res.second << "\n";
    return 0;
}
