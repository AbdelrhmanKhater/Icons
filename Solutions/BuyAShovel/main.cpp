#include <bits/stdc++.h>

using namespace std;
int k, r;
int Greedy_Solve()
{
    int ret = 0;
    int i = k;
    while (true)
    {
        if ((i % 10) == r)
            break;
        if (!(i % 10))
            break;
        i += k;
    }
    ret = i / k;
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> k >> r;
    cout << Greedy_Solve() << "\n";
    return 0;
}
