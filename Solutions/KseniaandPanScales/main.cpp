#include <bits/stdc++.h>

using namespace std;
string seq, w;
int w1, w2;
int siz1, siz2;
int last = 0, dif;
bool f;
int main()
{
    cin >> seq >> w;
    for (int i = 0; i < seq.size(); i++)
        if (seq[i] == '|')
        {
            w1 = i;
            break;
        }
    w2 = seq.size() - 1 - w1;
    dif = abs(w1 - w2);
    if ((w.size() >= dif) && ((w.size() - dif) % 2 == 0))
    {
        siz1 = (w.size() - dif) / 2;
        siz2 = w.size() - siz1;
        if (w1 < w2)
            swap(siz1, siz2);
        for (int i = 0; i < siz1; i++)
            cout << w[last++];
        cout << seq;
        for (int i = 0; i < siz2; i++)
            cout << w[last++];
        cout << "\n";
    }
    else
        cout << "Impossible\n";
    return 0;
}
