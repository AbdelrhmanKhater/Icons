#include <bits/stdc++.h>

using namespace std;
int n, d, i = 0;
int cnt = 0;
int memo[105];
string route;
queue<int> g;
int cur, tmp;
map<int, int> lvl;
int siz;
int DP_Solve(int idx)
{
    if (memo[idx] != -1)
        return memo[idx];
    if (idx == n - 1)
        return memo[idx] = 0;
    if (route[idx] == '0')
        return memo[idx] = 1000000000;
    int ret = 1000000000;
    for (int i = 1; i <= d; i++)
        ret = min(ret, DP_Solve(idx + i));
    return memo[idx] = ret + 1;
}
int BFS()
{
    int lev = 0;
    cur = 0;
    g.push(cur);
    while (g.size())
    {
        siz = g.size();
        while (siz--)
        {
            cur = g.front();
            g.pop();
            if (cur == n - 1)
                return lev;
            if (lvl.count(cur) != 0)
                continue;
            lvl[cur] = lev;
            for (int i = 1; i <= d; i++)
                if ((cur + i) < n && route[cur + i] == '1')
                   g.push(cur + i);
        }
        lev++;
    }
    return -1;
}
int Check(int s, int e)
{
    int ret = -1;
    e = min(e, n - 1);
    for (int i = e; i > s; i--)
        if (route[i] == '1')
            return i;
    return ret;
}
int main()
{
    cin >> n >> d >> route;
    /*while (i != n - 1)
    {
        i = Check(i, i + d);
        if (i == -1)
        {
            cnt = i;
            break;
        }
        else
            cnt++;
    }
    cout << cnt << "\n";*/
    /*memset(memo, -1, sizeof memo);
    cnt = DP_Solve(0);
    if (cnt < 1000000)
        cout << cnt << "\n";
    else
        cout << "-1\n";*/
    cout << BFS();
    return 0;
}
