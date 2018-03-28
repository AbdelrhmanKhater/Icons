#include <bits/stdc++.h>

using namespace std;
int nxt[3][5005], freq[3];
int n, x;
void Greedy_Solve()
{
    int mn = 1000000000;
    for (int i = 0; i < 3; i++)
        mn = min(mn, freq[i]);
    cout << mn << "\n";
    for (int i = 0; i < mn; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << nxt[j][i] << " ";
        cout << "\n";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        nxt[x - 1][freq[x - 1]] = i;
        freq[x - 1]++;
    }
    Greedy_Solve();
    return 0;
}
