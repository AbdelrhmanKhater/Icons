#include <bits/stdc++.h>
using namespace std;
int k;
bool Check(int n)
{
     int res = 0;
     while (n)
     {
         res += n % 10;
         n /= 10;
     }
     return res == 10;
}
int DP_Solve(int n)
{
    int ret = 0;
    if (n == 1)
       return 19;
    ret = DP_Solve(n - 1) + 9;
    if (Check(ret))
       return ret;
    while (!Check(ret))
            ret += 9;
    return ret;
}
int main()
{
    cin >> k;
    cout << DP_Solve(k) << "\n";
    return 0;
}
