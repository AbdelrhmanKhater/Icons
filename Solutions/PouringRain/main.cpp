#include <bits/stdc++.h>

using namespace std;
double d, h, v, e;
double r;
int main()
{
    cin >> d >> h >> v >> e;
    r = d / 2;
    v /= acos(-1) * pow(r, 2.0);
    if ((h / (v - e)) > 0 && (h / (v - e)) < 10000)
    {
        cout << "YES\n";
        cout << fixed << setprecision(12) << h / (v - e) << "\n";
    }
    else
        cout << "NO\n";
    return 0;
}
