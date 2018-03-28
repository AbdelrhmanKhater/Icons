#include <bits/stdc++.h>

using namespace std;
int step, mod;
int vis[100005];
/*void Rec_Solve(int s)
{
    if (vis[s] != -1)
        return;
    vis[s] = 1;
    Rec_Solve((s + step) % mod);
}*/
void Greedy_Solve()
{
    int s = 0;
    while (true)
    {
        if (vis[s] != -1)
            break;
        vis[s] = 1;
        s = (step + s) % mod;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> step >> mod)
    {
        memset(vis, -1, sizeof vis);
        Greedy_Solve();
        int cnt = 0;
        for (int i = 0; i < mod; i++)
            if (vis[i] != -1)
                cnt++;
        cout << setw(10) << step;
        cout << setw(10) << mod;
        cout << setw(4) << " ";
        if (cnt == mod)
            cout << "Good Choice\n\n";
        else
            cout << "Bad Choice\n\n";
    }
    return 0;
}
