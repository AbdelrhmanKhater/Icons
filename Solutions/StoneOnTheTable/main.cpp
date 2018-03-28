#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
string colors;
void Greedy_Solve()
{
    for (int i = 1; i < n; i++)
        if (colors[i] == colors[i - 1])
            cnt++;
}
int main()
{
    cin >> n >> colors;
    Greedy_Solve();
    cout << cnt << "\n";
    return 0;
}
