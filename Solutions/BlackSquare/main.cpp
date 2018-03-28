#include <bits/stdc++.h>

using namespace std;
int freq[4];
string game;
int cnt = 0;
void Greedy_Solve()
{
    for (int i = 0; i < game.length(); i++)
        cnt += freq[game[i] - '1'];
}
int main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i < 4; i++)
        cin >> freq[i];
    cin >> game;
    Greedy_Solve();
    cout << cnt << "\n";
    return 0;
}
