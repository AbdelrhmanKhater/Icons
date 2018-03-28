#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

int n, m, component[100005], ways[100005], cost[100005], stck[100005], cnt_stck = 0;
int min_cost[100005], x, y, idx[100005], low[100005], Scc = -1;
vector<int> tree[100005];
bool vis[100005];

void tarjan(int ind)
{
    static int t = 0;
    idx[ind] = low[ind] = t++;
    stck[cnt_stck ++] = ind;
    vis[ind] = true;
    for (int i = 0; i < tree[ind].size(); i++)
    {
        if (idx[tree[ind][i]] == -1)
        {
            tarjan(tree[ind][i]);
            low[ind] = min(low[ind], low[tree[ind][i]]);
        }
        else if(vis[tree[ind][i]])
            low[ind] = min(low[ind], idx[tree[ind][i]]);
    }
    if (idx[ind] == low[ind])
    {
        Scc++;
        int u = -1;
        do
        {
           u = stck[--cnt_stck];
           vis[u] = false;
           component[u] = Scc;
        }while(u != ind);
    }
}
void scc()
{
    memset(idx, -1, sizeof idx);
    for (int i = 0; i < n; i++)
        if(idx[i] == -1)
            tarjan(i);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n;scanf("%d", &cost[i]), i++);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d",&x,&y);
        tree[x - 1].push_back(y - 1);
    }
    scc();
    memset(min_cost, -1, sizeof min_cost);
    for (int i = 0; i < n; i++)
    {
        if (cost[i] == min_cost[component[i]])
            ways[component[i]]++;
        else if (cost[i] < min_cost[component[i]] || min_cost[component[i]] == -1)
        {
            min_cost[component[i]] = cost[i];
            ways[component[i]] = 1;
        }
    }
    long long ret = 0, way = 1;
    for (int i = 0; i <= Scc; i++)
    {
        ret += min_cost[i];
        way *= ways[i];
        way %= 1000000007;
    }
    printf("%I64d %I64d\n", ret, way);
}
