#include <bits/stdc++.h>

using namespace std;
int n, x, cnt_A = 0, cnt_S = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cnt_A = 0;
        for (int j = 0; j < 3; j++)
        {
            cin >> x;
            if (x == 1)
                cnt_A++;
        }
        if (cnt_A > 1)
            cnt_S++;
    }
    cout << cnt_S << "\n";
    return 0;
}
