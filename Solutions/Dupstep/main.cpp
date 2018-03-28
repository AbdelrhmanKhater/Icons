#include<bits/stdc++.h>
using namespace std;
string song, fsong = "";
bool Check(int idx)
{
    bool cond = (idx + 2) < song.size();
    return ((idx + 2) < song.size() && song[idx] == 'W' && song[idx + 1] == 'U' && song[idx + 2] == 'B');
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> song;
    for (int i = 0; i < song.size(); i++)
    {
        if (Check(i) && fsong.size() != 0 && fsong[fsong.size() - 1] != ' ')
        {
            i += 2;
            fsong += " ";
        }
        else if (Check(i))
            i += 2;
        else
            fsong += song[i];
    }
    cout << fsong << "\n";
    return 0;
}
