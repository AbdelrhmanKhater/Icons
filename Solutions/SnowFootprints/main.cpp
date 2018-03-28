#include <bits/stdc++.h>

using namespace std;
int n;
string desc;
int dir[2][2];
bool cond1 = false, cond2 = false;
int main()
{
    ios::sync_with_stdio(false);
    dir[0][0] = 1000000009;
    dir[1][0] = 1000000009;
    cin >> n >> desc;
    for (int i = 0; i < n; ++i)
        if (desc[i] == 'R')
        {
            dir[0][0] = min(dir[0][0], i);
            dir[0][1] = i;
            cond1 = true;
        }
        else if (desc[i] == 'L')
        {
            dir[1][0] = min(dir[1][0], i);
            dir[1][1] = i;
            cond2 = true;
        }
    if (cond1 && cond2)
        cout << dir[0][0] + 1 << " " << dir[0][1] + 1 << "\n";
    else if (cond1)
        cout << dir[0][0] + 1 << " " << dir[0][1] + 2 << "\n";
    else
        cout << dir[1][1] + 1 << " " << dir[1][0] << "\n";
    return 0;
}
