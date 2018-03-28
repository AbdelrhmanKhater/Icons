#include <bits/stdc++.h>

using namespace std;
int n;
string s;
void Greedy_Solve()
{
    int f = 2;
    int x = 0, y = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U')
            y++;
        else x++;
        if (x > y && f == 1)
        {
            f = 0;
            cnt++;
        }
        else if (y > x && f == 0)
        {
            f = 1;
            cnt++;
        }
        else if (y > x && f == 2)
            f = 1;
        else if (x > y && f == 2)
            f = 0;
    }
    cout << cnt << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> s;
    Greedy_Solve();
    return 0;
}
