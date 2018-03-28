#include <bits/stdc++.h>

using namespace std;
string w, res;
void To_Lower()
{
    for (int i = 0; i < w.size(); i++)
        if (w[i] >= 'A' && w[i] <= 'Z')
            w[i] += 'a' - 'A';
}
void Reverse()
{
    for (int i = 0; i < w.size() / 2; i++)
        swap(w[i], w[w.size() - 1 - i]);
}
void Greedy_Solve()
{
    res = "";
    for (int i = 0; i < w.size(); i++)
        if (w[i] != 'i' && w[i] != 'e' && w[i] != 'o' && w[i] != 'u' && w[i] != 'y' && w[i] != 'a')
        {
            res += '.';
            res += w[i];
        }
    /*for (int i = 0; i < res.size() / 2; i++)
        swap(res[i], res[res.size() - 1 - i]);*/
    cout << res << "\n";
}
int main()
{
    cin >> w;
    To_Lower();
    //Reverse();
    Greedy_Solve();
    return 0;
}
