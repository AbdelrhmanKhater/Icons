#include <bits/stdc++.h>

using namespace std;

int x[100005];
int n;
void Greedy_Solve()
{
    int mn, mx;
    for (int i = 0; i < n; i++)
    {
        mn = 2000000009;
        if (i != 0)
            mn = abs(x[i - 1] - x[i]);
        if (i != n - 1)
            mn = min(mn, abs(x[i + 1] - x[i]));
        mx = max(abs(x[0] - x[i]), abs(x[n - 1] - x[i]));
        cout << mn << " " << mx << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    Greedy_Solve();
    return 0;
}
