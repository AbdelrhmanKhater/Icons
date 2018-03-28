#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;
struct node
{
    int idx, dis;
};
bool operator<(node i, node j)
{
    if (i.dis != j.dis)
        return i.dis < j.dis;
    return i.idx < j.idx;
}
node nodes[100005];
node cur, tmp;
int ans[100005];
set <node> S;
vector<int> cities[100005];
vector<int> roads[100005];
int Dijkstra_Solve(int s, int e)
{
    cur.idx = s;
    cur.dis = 0;
    S.insert(cur);
    while (S.size())
    {
        cur = *S.begin();
        S.erase(S.begin());
        if (ans[cur.idx] != -1) continue;
        ans[cur.idx] = cur.dis;
        if (cur.idx == e)
            return ans[cur.idx];
        for (int i = 0; i < cities[cur.idx].size(); i++)
        {
            tmp.idx = cities[cur.idx][i];
            tmp.dis = cur.dis + roads[cur.idx][i];
            S.insert(tmp);
        }
    }
    return ans[e];
}
int n, m;
int s, e;
int x, y, z;
int t;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> s >> e;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> z;
            cities[x].push_back(y);
            cities[y].push_back(x);
            roads[x].push_back(z);
            roads[y].push_back(z);
        }
        memset(ans, -1, sizeof ans);
        int res = Dijkstra_Solve(s, e);
        if (res != -1)
            cout << res << "\n";
        else
            cout << "NONE\n";
        for (int i = 1; i <= n; i++)
        {
            cities[i].clear();
            roads[i].clear();
        }
    }
    return 0;
}
