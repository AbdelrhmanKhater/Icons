#include <bits/stdc++.h>

using namespace std;
int wires[105];
int n, m, x, y;
void Math_Solve(int x, int y)
{
    x -= 1;
    if (x != 0)
        wires[x - 1] += y - 1;
    if (x != (n - 1))
        wires[x + 1] +
        = wires[x] - y;
    wires[x] = 0;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> wires[i];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        Math_Solve(x,y);
    }
    for (int i = 0; i < n; i++)
        cout << wires[i] << "\n";
    return 0;
}
