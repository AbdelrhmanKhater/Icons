#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> g[105];
int x, y;
int vis[105];
int DFS(int node, int parent)
{
    vis[node] = 1;
    int ret = 0;
    for (int i = 0; i < g[node].size(); i++)
        if (vis[g[node][i]] && g[node][i] != parent)
            return 1;
        else if (!vis[g[node][i]])
        {
                ret = DFS(g[node][i], node);
                if (ret)
                    return 1 + ret;
        }
    return ret;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cnt = 0, enm = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            enm = DFS(i, i);
            if (enm % 2)
                cnt++;
        }
    if ((n - cnt) % 2)
        cout << ++cnt << "\n";
    else
        cout << cnt << "\n";
    return 0;
}
