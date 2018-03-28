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
    int idx, t;
};
bool operator< (node i, node j)
{
    if (i.t != j.t)
        return i.t < j.t;
    return i.idx < j.idx;
}

int e;
set<node> S;
node cur, tmp;
int ans[105];
int n, m, t;
int x, y, z;
vector<int> cells[105];
vector<int> tim[105];
void Dijkstra_Solve(int s)
{
    cur.idx = s;
    cur.t = 0;
    S.insert(cur);
    while (!S.empty())
    {
        cur = *S.begin();
        S.erase(S.begin());
        if (cur.t > t) break;
        if (ans[cur.idx] != -1) continue;
        ans[cur.idx] = cur.t;
        for (int i = 0; i < cells[cur.idx].size(); i++)
        {
            tmp.idx = cells[cur.idx][i];
            tmp.t = tim[cur.idx][i] + cur.t;
            S.insert(tmp);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (ans[i] <= t && ans[i] != -1)
            cnt++;
    cout << cnt << "\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    memset(ans, -1, sizeof ans);
    cin >> n >> e >> t >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        cells[y].push_back(x);
        tim[y].push_back(z);
    }
    Dijkstra_Solve(e);
    return 0;
}
