#include <bits/stdc++.h>

using namespace std;

struct component
{
    int x, y, cst;
};
int n, x;
component comps[10005];
int p[105];
int r[105];
int xr, yr;
int cnt;
bool cmp(component i, component j)
{
    if (i.cst != j.cst)
        return i.cst < j.cst;
    if (i.x != j.x)
        return i.x < j.x;
    return i.y < j.y;
}
void Create(int node)
{
    p[node] = node;
    r[node] = 1;
}
int Find(int node)
{
    if (p[node] != node)
        p[node] = Find(p[node]);
    return p[node];
}
void Merge(int xr, int yr)
{
    int rx = r[xr], ry = r[yr];
    if (rx > ry)
        p[yr] = xr;
    else
        p[xr] = yr;
    if (rx == ry)
        r[yr]++;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            comps[i * n+ j].x = i;
            comps[i * n + j].y = j;
            comps[i * n + j].cst = x;
        }
    sort(comps, comps + (n * n), cmp);
    for (int i = 0; i < n; i++)
        Create(i);
    cnt = 0;
    for (int i = 0; i < n * n; i++)
    {
        xr = Find(comps[i].x);
        yr = Find(comps[i].y);
        if (xr != yr)
        {
            Merge(xr, yr);
            cnt += comps[i].cst;
        }
    }
    cout << cnt << "\n";
    return 0;
}
