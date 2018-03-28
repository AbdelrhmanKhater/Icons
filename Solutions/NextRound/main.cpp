#include <bits/stdc++.h>

using namespace std;
int n, k;
int num[55];
int Find_End(int s, int e, int key)
{
    if (s > e)
        return e;
    int mid = (s + e) / 2;
    if (num[mid] == key)
        return Find_End(mid + 1, e, key);
    return Find_End(s, mid - 1, key);
}
int Find_Start(int s, int e, int key)
{
    if (s > e)
        return s;
    int mid = (s + e) / 2;
    if (num[mid] == key)
        return Find_Start(s, mid - 1, key);
    return Find_Start(mid + 1, e, key);
}
void Greedy_Solve()
{
    int res = 0;
    if (num[k - 1])
        res = Find_End(k - 1, n - 1, num[k - 1]) + 1;
    else if (Find_Start(0, k - 1, num[k - 1]) != 0)
        res = Find_Start(0, k - 1, num[k - 1]);
    cout << res << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    Greedy_Solve();
    return 0;
}
