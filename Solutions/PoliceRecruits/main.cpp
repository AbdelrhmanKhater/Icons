#include <bits/stdc++.h>

using namespace std;
int n, events[100005];
int Greedy_Solve()
{
    int cnt_O = 0, cnt_C = 0;
    for (int i = 0; i < n; i++)
        if (events[i] > 0)
            cnt_O += events[i];
        else
            if (cnt_O)
                cnt_O--;
            else
                cnt_C++;
    return cnt_C;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> events[i];
    cout << Greedy_Solve() << "\n";
    return 0;
}
