#include <bits/stdc++.h>

using namespace std;

int n, cnt_c = 0;
long long cnt_p;
pair<char, int> packs[1005];
void Greedy_Solve()
{
    for (int i = 0; i < n; i++)
        if (packs[i].first == '+')
            cnt_p += packs[i].second;
        else
            if (packs[i].second > cnt_p)
                cnt_c++;
            else
                cnt_p -= packs[i].second;
}
int main()
{
    cin >> n >> cnt_p;
    for (int i = 0; i < n; i++)
        cin >> packs[i].first >> packs[i].second;
    Greedy_Solve();
    cout << cnt_p << " " << cnt_c << "\n";
    return 0;
}
