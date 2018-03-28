#include <bits/stdc++.h>

using namespace std;
int n, h, x;
int cnt = 0;
int main()
{
    cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x > h)
            cnt++;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
