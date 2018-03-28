#include <bits/stdc++.h>

using namespace std;

int n, k, t, d;
void Math_Solve()
{
    int mx;
    int cnt = (n + k - 1) / k;
    int t1 = (cnt) * t;
    int mn_s = (d + t - 1) / t;
    if (mn_s >= cnt)
    {
        cout << "NO\n";
        return;
    }
    int t1_c = mn_s * t;
    cnt -= mn_s;
    int t2_c = d;
    if (t1_c > t2_c)
    {
        t1_c += (cnt - ((cnt + 1) / 2)) * t;
        t2_c += ((cnt + 1) / 2) * t;
        mx = max(t1_c, t2_c);
    }
    else
    {
        t1_c += ((cnt + 1) / 2) * t;
        t2_c += (cnt - ((cnt + 1) / 2)) * t;
        mx = max(t1_c, t2_c);
    }
    if (mx < t1)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    cin >> n >> t >> k >> d;
    Math_Solve();
    return 0;
}
