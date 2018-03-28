#include <bits/stdc++.h>

using namespace std;
int mx, n, d;
int oranges[1000005];
int Greedy_Solve()
{
    int siz = 0, ret = 0;
    for (int i = 0; i < n; i++)
        if (oranges[i] <= mx)
        {
            siz += oranges[i];
            ret += siz / (d + 1);
            if (siz > d)
                siz = 0;
        }
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> mx >> d;
    for (int i = 0; i < n; i++)
        cin >> oranges[i];
    cout << Greedy_Solve() << "\n";
    return 0;
}
