#include <bits/stdc++.h>

using namespace std;
int n;
int num[105];
int total = 0;
pair<int, int> Pivot(int s, int e)
{
    int x = s;
    for (int i = s + 1; i <= e; i++)
        if (num[i] >= num[s])
            swap(num[++x], num[i]);
    swap(num[s], num[x]);
    int j = x;
    for (int i = x - 1; i > -1; i--)
        if (num[i] == num[x])
            swap(num[--j], num[i]);
    return make_pair(j, x);
}
void Quick_Sort(int s, int e)
{
    if (s >= e)
        return;
    pair<int, int> mid = Pivot(s, e);
    Quick_Sort(s, mid.first - 1);
    Quick_Sort(mid.second + 1, e);
}
void Greedy_Solve()
{
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        sum += num[i];
        cnt++;
        if (sum > (total - sum))
            break;
    }
    cout << cnt << "\n";
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        total += num[i];
    }
    Quick_Sort(0, n - 1);
    Greedy_Solve();
    return 0;
}
