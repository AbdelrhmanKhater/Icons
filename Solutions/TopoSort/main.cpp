#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> jobs[10005];
int imp[10005];
vector<int> ans;
vector<int> ans1;
int vis[10005];
int x, y;
int cnt[10001];
set<int> S;
void DFS(int node)
{
    vis[node] = 1;
    ans.push_back(node);
    for (int i = 0; i < jobs[node].size(); i++)
    {
        imp[jobs[node][i]]--;
        if ((!imp[jobs[node][i]]) && (!vis[jobs[node][i]]))
            S.insert(jobs[node][i]);
    }
    if (!S.empty())
    {
        node = *S.begin();
        S.erase(S.begin());
        DFS(node);
    }
}
void Merge(vector<int>::iterator v, int s, int mid, int e)
{
    int n1 = mid - s + 1, n2 = e - mid;
    vector<int> arr1(n1, 0), arr2(n2, 0);
    for (int i = 0; i < n1; i++)
        arr1[i] = v[s + i];
    for (int i = 0; i < n2; i++)
        arr2[i] = v[mid + 1 + i];
    int i = 0, j = 0, siz = s;
    while ((i < n1) && (j < n2))
        if (arr1[i] < arr2[j])
            v[siz++] = arr1[i++];
        else
            v[siz++] = arr2[j++];
    while (i < n1)
        v[siz++] = arr1[i++];
    while (j < n2)
        v[siz++] = arr2[j++];
}
void Merge_Sort(vector<int>::iterator v, int s, int e)
{
    if (s == e)
        return;
    int mid = (s + e) / 2;
    Merge_Sort(v, s, mid);
    Merge_Sort(v, mid + 1, e);
    Merge(v, s, mid, e);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        jobs[x].push_back(y);
        ++imp[y];
    }
    for (int i = 1; i <= n; i++)
        if ((!imp[i]))
            S.insert(i);
    int node;
    while (!S.empty())
    {
        node = *S.begin();
        S.erase(S.begin());
        ans.push_back(node);
        for (int i = 0; i < jobs[node].size(); i++)
        {
            imp[jobs[node][i]]--;
            if(!imp[jobs[node][i]])
                S.insert(jobs[node][i]);
        }
    }
    if (ans.size() != n)
        cout << "Sandro fails.";
    else
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
    cout << "\n";
    return 0;
}

