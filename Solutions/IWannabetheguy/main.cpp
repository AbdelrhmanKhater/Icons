#include <bits/stdc++.h>

using namespace std;
int n, p, q;
int lvl[105], lev;
bool Check()
{
    for (int i = 1; i <= n; i++)
        if (lvl[i] != 1)
            return false;
    return true;
}
int main()
{
    cin >> n;
    cin >> p;
    memset(lvl, -1, sizeof lvl);
    for (int i = 0; i < p; i++)
    {
        cin >> lev;
        lvl[lev] = 1;
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> lev;
        lvl[lev] = 1;
    }
    if (Check())
        cout << "I become the guy.\n";
    else
        cout << "Oh, my keyboard!\n";
    return 0;
}
