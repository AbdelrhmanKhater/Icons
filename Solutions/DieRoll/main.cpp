#include <bits/stdc++.h>

using namespace std;
int y, w, chs, e = 6, mx, gcd;
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
int Math_Solve()
{
    mx = max(y, w);
    chs = e - mx + 1;
    gcd = GCD(e, chs);
    chs /= gcd;
    e /= gcd;
    cout << chs << "/" << e << "\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> y >> w;
    Math_Solve();
    return 0;
}
