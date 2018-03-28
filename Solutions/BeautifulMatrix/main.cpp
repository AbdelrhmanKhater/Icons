#include <bits/stdc++.h>

using namespace std;
int x, px, py, mx, my;
int main()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            cin >> x;
            if (x == 1)
            {
                px = i;
                py = j;
            }
        }
    mx = abs(px - 2);
    my = abs(py - 2);
    cout << mx + my << "\n";
    return 0;
}
