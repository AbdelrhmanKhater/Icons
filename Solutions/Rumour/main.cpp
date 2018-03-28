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
int n, t;
int parent[105];
int x, y;
int idx = 0;
int idx1 = 0;
int Detect_Parent(int child)
{
    int parent;
    if (child == 1)
        return 0;
    if(child % 2)
    {
        parent = (child - 1) / 2;
        parent[child] = 1 + Detect_Parent(parent);
    }
    else
    {
        parent = child / 2;
        parent[child] = 1 + Detect_Parent(child / 2);
    }
    lft[idx++] = parent;
    return parent[child];
}
int Detect_Parent(int child)
{
    int parent;
    if (child == 1)
        return;
    if(child % 2)
    {
        parent = (child - 1) / 2;
        parent[child] = 1 + Detect_Parent(parent);
    }
    else
    {
        parent = child / 2;
        parent[child] = 1 + Detect_Parent(child / 2);
    }
    rht[idx1++] = parent;
    return parent[child];
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    while (n--)
    {
        meset(lft, 0, sizeof lft);
        memset(rht, 0, sizeof rht);
        cin >> x >> y;
        Detect_Parent(x);
        Detect_parent(y);
        sort(lft, lft + idx);
        sort(rht, rht + idx1);
        for (int i = idx - 1; i >= 0; i++)
            for (int j = idx1 - 1; j >= 0; j++)
            {
                if (lft[i] == rht[j])
                {
                    cout <<
                }
            }
    }
    return 0;
}
