#include <bits/stdc++.h>

using namespace std;
int n;
int cards[1005];
int cnt_S, cnt_D;
void Play()
{
    int s = 0, e = n - 1;
    bool f = true;
    while (s <= e)
    {
        if (cards[s] > cards[e])
            if (f)
                cnt_S += cards[s++];
            else
                cnt_D += cards[s++];
        else
            if (f)
                cnt_S += cards[e--];
            else
                cnt_D += cards[e--];
        f = !f;
    }

}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cards[i];
    Play();
    cout << cnt_S << " " << cnt_D << "\n";
    return 0;
}
