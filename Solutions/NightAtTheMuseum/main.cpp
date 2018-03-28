#include <bits/stdc++.h>

using namespace std;
string name;
int Greedy_Solve()
{
    int cur = 0, ret = 0, tmp, dis;
    for (int i = 0; i < name.length(); i++)
    {
        tmp = name[i] - 'a';
        dis = abs(tmp - cur);
        if (dis > 13)
            ret += 26 - dis;
        else
            ret += dis;
        cur = tmp;
    }
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> name;
    cout << Greedy_Solve() << "\n";
    return 0;
}
