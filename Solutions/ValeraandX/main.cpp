#include <bits/stdc++.h>

using namespace std;
int n;
char grid[300][300];
int freq[35];
bool Check()
{
    bool cond1 = false, cond2 = false;
    for (int i = 0; i < 35; i++)
    {
        if (freq[i] == 2 * n - 1)
            cond1 = true;
        if (freq[i] == (n - 2) * n + 1)
            cond2 = true;
    }
    return cond1 && cond2;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n * n; i++)
    {
        cin >> grid[i / n][i % n];
        freq[grid[i / n][i % n] - 'a']++;
    }
    if (Check())
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (grid[i][i] != grid[i][n - 1 - i] || grid[i][i] != grid[i + 1][i + 1] || grid[i][n - 1 - i] != grid[i + 1][n - 1 - i - 1])
            {
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
    }
    else
        cout << "NO\n";

    return 0;
}
