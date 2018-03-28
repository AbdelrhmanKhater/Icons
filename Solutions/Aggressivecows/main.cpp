#include <bits/stdc++.h>

using namespace std;
int t;
int stall[100005], n, c;
bool Check(int step)
{
    int dis = stall[0] + step, cnt = 1;
    for (int i = 1; i < n; ++i)
        if (dis <= stall[i])
        {
            dis = stall[i] + step;
            cnt++;
        }
    return cnt >= c;
}
int Binary_Solve()
{
    int s = 1, e = stall[n - 1] - stall[0], mid;
    int ret;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (Check(mid))
        {
            ret = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        for (int i = 0; i < n; ++i)
            cin >> stall[i];
        sort(stall, stall + n);
        cout << Binary_Solve() << "\n";
    }
    return 0;
}
