#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

struct query
{
    int e, idx;
};
int n, q, BIT[30005], y, x, mx, nxt[30005], last[1000005], nums[30005];
int ans[200005];
bool vis[1000005];
vector<query> queries[30005];
query cur;

void update(int idx)
{
    if (idx == 0) return;
    for (int i = idx; i <= n; i += (i & -i))
        BIT[i]++;
}
int solve(int idx)
{
    int ret = 0;
    for (int i = idx; i ; i -= (i & -i))
        ret += BIT[i];
    return ret;
}
void nxt_trick()
{
    for (int i = 0; i < n; i++)
    {
        if (last[nums[i]] != -1)
            nxt[last[nums[i]]] = i + 1;
            last[nums[i]] = i + 1;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (!vis[x])
        {
            vis[x] = true;
            update(i + 1);
        }
        nums[i] = x;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &x , &y);
        cur.e = y, cur.idx = i;
        mx = max(mx, x);
        queries[x].push_back(cur);
    }
    memset(last, -1, sizeof last);
    nxt_trick();
    for (int i = 1; i <= mx ; i++)
    {
        for (int j = 0; j < queries[i].size(); j++)
        {
            ans[queries[i][j].idx] = solve(queries[i][j].e) - solve(i - 1);
        }
        update(nxt[i]);
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", ans[i]);
    return 0;
}
