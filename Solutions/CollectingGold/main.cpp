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
#include <map>
#include <queue>
#include <stdio.h>

using namespace std;
int sieve[100];
long long Tmp[100];
int idx;
int n, m;
long long x, y;
int dis;
vector<int> tree[20005];
vector<long long> ids;
vector<int> csts[20005];
map <string,int> d;
struct node
{
    int idx, cst, sol;
};
int ans[20005];
node nodes[20005];
node cur, tmp;
bool operator <(node i, node j)
{
    if (i.cst != j.cst)
        return i.cst < j.cst;
    if (i.idx != j.idx)
        return i.idx < j.idx;
    return i.sol < j.sol;
}
set<node> S;
void Generate_Sieve()
{
    for (int i = 2; i < 100; i++)
        sieve[i] = 1;
    for (int i = 2; i < 100; i++)
        if (sieve[i] == 1)
            for (int j = 2 * i; j < 100; j += i)
                sieve[j] = 0;
}
void Generate_Tmp()
{
    int fact = 1;
    for (int i = 0; i < 100; i++)
        if (sieve[i])
        {
            fact *= i;
            Tmp[idx++] = fact;
        }
}
int Binary_Search(int val)
{
    int s = 0, e = 8, mid, ret;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (Tmp[mid] <= val)
        {
            ret = mid;
            s = mid + 1;
        }
        else if (Tmp[mid] > val)
            e = mid - 1;
    }
    return ret = e;
}
int Dijkstra_Solve(int s, int e)
{
    cur.idx = s;
    cur.cst = 0;
    int v = ids[cur.idx];
    cur.sol = Binary_Search(v) + 1;
    S.insert(cur);
    while (S.size())
    {
        cur = *S.begin();
        S.erase(S.begin());
        if(ans[cur.idx] != -1)
            continue;
        ans[cur.idx] = cur.sol;
        if(cur.idx == e)
            return ans[cur.idx];
        for (int i = 0; i < tree[cur.idx].size(); i++)
        {
            tmp.idx = tree[cur.idx][i];
            tmp.cst = cur.cst + csts[cur.idx][i];
            tmp.sol = cur.sol + Binary_Search(ids[tmp.idx]) + 1;
            S.insert(tmp);
        }
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    cin >> n >> m;
    string e, r;
    memset(ans, -1, sizeof ans);
    Generate_Sieve();
    Generate_Tmp();
    for (int i = 0; i < n; i++)
        {
            cin >> e;
            stringstream s(e);
            s >> x;
            ids.push_back(x);
            d[e] = i;
        }
    for (int i = 0; i < m; i++)
    {
        string e, r;
        cin >> e >> r >> dis;
        tree[d[e]].push_back(d[r]);
        tree[d[r]].push_back(d[e]);
        csts[d[e]].push_back(dis);
        csts[d[r]].push_back(dis);
        //cout << " " <<d[e] << " " << d[r] << endl;
    }
    int ss, ee;
    ee = max_element(ids.begin(), ids.end()) - ids.begin();
    ss = min_element(ids.begin(), ids.end()) - ids.begin();
    cout << Dijkstra_Solve(ss, ee);
    return 0;
}
