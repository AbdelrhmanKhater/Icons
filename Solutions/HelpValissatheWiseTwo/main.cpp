#include <bits/stdc++.h>

using namespace std;
int r1, r2, c1, c2, d1, d2;
int x, y, a, b, res;
bool f = false;
set<int> ans;
int main()
{
    cin >> r1 >> r2;
    cin >> c1 >> c2;
    cin >> d1 >> d2;
    res = (c2 + d1) - r1;
    if (!(res % 2))
    {
        b = res / 2;
        x = d1 - b;
        y = c2 - b;
        a = r2 - b;
        ans.insert(b);
        ans.insert(x);
        ans.insert(y);
        ans.insert(a);
        if (x < 1 || y < 1 || a < 1 || ans.size() < 4 || x + a != c1 || y + a != d2 || x > 9 || y > 9 || a > 9 || b > 9)
            f = true;
        else
        {
            cout << x << " " << y << "\n";
            cout << a << " " << b << "\n";
        }
    }
    if (res % 2 || f)
        cout << "-1\n";
    return 0;
}
