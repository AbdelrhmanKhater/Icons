#include <bits/stdc++.h>

using namespace std;
double xpt = 0, ypt = 0, tmpx = 0, tmpy = 0;
double res;
int n, k;
double Maths_Solve(double x1, double y1, double x2, double y2)
{
    double root1, root2, ret;
    root1 = pow(abs(x1 - x2), 2.0);
    root2 = pow(abs(y1 - y2), 2.0);
    ret = pow(root1 + root2, 0.5);
    return ret;
}
int main()
{
    cin >> n >> k;
    cin >> tmpx >> tmpy;
    for (int i = 1; i < n; i++)
    {
        cin >> xpt >> ypt;
        res += Maths_Solve(tmpx, tmpy, xpt, ypt);
        tmpx = xpt;
        tmpy = ypt;
    }
    cout << fixed << setprecision(9) << res * k / 50.0 << "\n";
    return 0;
}
