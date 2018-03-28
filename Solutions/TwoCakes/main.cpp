#include <bits/stdc++.h>

using namespace std;
int pl, fc, sc;
bool Check(int step)
{
    int p = (fc / step) + (sc / step);
    return p >= pl;
}
int Binary_Search_Solve()
{
    int ret = 1;
    int s = 1, e = min(fc, sc), mid;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (Check(mid))
        {
            ret = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ret;
}
int main()
{
    cin >> pl >> fc >> sc;
    cout << Binary_Search_Solve() << "\n";
    return 0;
}
