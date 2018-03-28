#include <bits/stdc++.h>

using namespace std;
int hit, heal = 0;
int atk1, h1, hl1, atk2, h2;
void Maths_Solve()
{
    hit = (h2 + atk1 - 1) / atk1;
    h1 -= (hit - 1) * atk2;
    if (h1 <= 0)
        heal = ((-h1) / (hl1- atk2)) + 1;
}
int main()
{
    cin >> h1 >> atk1 >> hl1 >> h2 >> atk2;
    Maths_Solve();
    cout << heal + hit << "\n";
    for (int i = 0; i < heal; i++)
        cout << "HEAL\n";
    for (int i = 0; i < hit; i++)
        cout << "STRIKE\n";
    return 0;
}
