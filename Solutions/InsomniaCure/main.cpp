#include <bits/stdc++.h>

using namespace std;
int num[4];
int d;
set<int> nums;
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}
bool Check()
{
    for (int i = 0; i < 4; i++)
        if (num[i] == 1)
        return true;
    return false;
}
int Inc_Solve(int idx, int div, int sign)
{

    if (idx == 4)
    {
        if (div == 1)
            return 0;
        return sign * (d / div);
    }
    return Inc_Solve(idx + 1, div, sign) + Inc_Solve(idx + 1, LCM(div, num[idx]), -1 * sign);
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> num[0] >> num[1] >> num[2] >> num[3] >> d;
    if (Check())
        cout << d << "\n";
    else
        cout << Inc_Solve(0, 1, -1) << "\n";
        /*for (int i = 0; i < 4; i++)
            for (int j = 1; j <= d; j++)
                if (j % num[i] == 0)
                    nums.insert(j);
        cout << nums.size() << "\n";*/
    return 0;
}
