#include <bits/stdc++.h>

using namespace std;
struct Clothes
{
    int h, g;
};
int n;
int memo[105];
Clothes uni[35];
int Greedy_Solve()
{
    int ret = 0, cnt;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        if (memo[uni[i].h] != -1)
            ret += memo[uni[i].h];
        else
        {
            for(int j = 0; j < n; j++)
                if (uni[i].h == uni[j].g)
                    cnt++;
            ret += cnt;
        }
    }
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    memset(memo, -1, sizeof memo);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> uni[i].h >> uni[i].g;
    cout << Greedy_Solve() << "\n";
    return 0;
}
