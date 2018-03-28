#include <bits/stdc++.h>

using namespace std;
long long v[100005], u[1000005];
int n, q, r, l;
int ty;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        u[i] = v[i];
        v[i] += v[i - 1];
    }
    sort(u, u + n + 1);
    for (int i = 1; i <= n; ++i)
        u[i] += u[i - 1];
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> ty >> l >> r;
        if (ty == 1)
            cout << v[r] - v[l - 1] << "\n";
        else
            cout << u[r] - u[l - 1] << "\n";
    }
    return 0;
}
