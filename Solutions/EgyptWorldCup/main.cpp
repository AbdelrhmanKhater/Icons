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

struct team
{
    string name;
    int pt;
};
bool cmp(team i, team j)
{
    return i.pt > j.pt;
}
team teams[105];
int t, n;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> teams[i].name >> teams[i].pt;
        sort(teams, teams + n, cmp);
        cout << teams[0].name << "\n";
    }

    return 0;
}
