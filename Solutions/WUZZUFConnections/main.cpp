#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;
struct node
{
    int idx, cst;
};

bool operator < (node i, node j)
{
    if(i.cst != j.cst)
        return i.cst < j.cst;
    return i.idx < j.idx;
}

int n, m, t;
int n1, n2;
int ans[1005];
vector<int> conns[1005];
set<node> nodes;
node cur, tmp;
void Dijkstra_Solve()
{
    cur.idx = 0;
    cur.cst = 0;
    nodes.insert(cur);
    while(nodes.size())
    {
        cur = *nodes.begin();
        nodes.erase(nodes.begin());
        if(ans[cur.idx] != -1) continue;
        ans[cur.idx] = cur.cst;
        for (int i = 0; i < conns[cur.idx].size(); i++)
        {
            tmp.idx = conns[cur.idx][i];
            tmp.cst = cur.cst + 1;
            nodes.insert(tmp);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        memset(ans, -1, sizeof ans);
        for (int i = 0; i < 1005; i++)
            conns[i].clear();
        cin >> n >> m;
        for (int i = 1; i < n; i++)
        {
            cin >> n1;
            if (n1)
                ans[i] = -2;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> n1 >> n2;
            conns[n1].push_back(n2);
            conns[n2].push_back(n1);
        }
        Dijkstra_Solve();
        for (int i = 1; i < n; i++)
            {
                if (ans[i] == -2)
                    cout << -1 << " ";
                else
                    cout << ans[i] << " ";
            }
        cout << "\n";
    }
    return 0;
}
