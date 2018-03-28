#include <bits/stdc++.h>

using namespace std;
string team;
string decd[2];
map<string, int> enc;
int freq[10], n;
int lvl = 0;
void Encode(string t)
{
    if (enc.count(t) == 0)
    {
        enc[t] = lvl;
        decd[lvl++] = t;
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> team;
        Encode(team);
        freq[enc[team]]++;
    }
    if (freq[0] > freq[1])
        cout << decd[0] << "\n";
    else
        cout << decd[1] << "\n";
    return 0;
}
