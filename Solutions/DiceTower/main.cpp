#include <bits/stdc++.h>

using namespace std;
int dice[105][2];
int x;
int n;
int main()
{
    cin >> n;
    cin >> x;
    for (int i = 0; i < n; i++)
        cin >> dice[i][0] >> dice[i][1];
    for (int i = 1; i < n; i++)
    {
        x = 7 - x;
        if (x == dice[i][0] || x == dice[i][1] || x ==  7 - dice[i][0] || x == 7 - dice[i][1])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
