#include <bits/stdc++.h>

using namespace std;
pair<int, int> freq[135];
bool cmp(pair<int, int> i, pair<int, int> j)
{
    if (i.second != j.second)
        return i.second < j.second;
    return i.first > j.first;
}
string w;
int f = 0;
int main()
{
    ios::sync_with_stdio(false);
    while (getline(cin, w))
    {
        if (f)
            cout << "\n";
        ++f;
        memset(freq, 0, sizeof freq);
        for (int i = 0; i < w.size(); ++i)
        {
            freq[w[i]].first = w[i];
            ++freq[w[i]].second;
        }
        sort(freq, freq + 135, cmp);
        for (int i = 0; i < 135; ++i)
            if (freq[i].second)
                cout << freq[i].first << " " << freq[i].second << "\n";
    }
    return 0;
}
