#include <bits/stdc++.h>

using namespace std;
int n, cnt = 1, i;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    /*for (int i = 1; i < n; i++)
        if ((n - i) % i == 0)
            cnt++;*/
    for (i = 2; i * i < n; i++)
        if (n % i == 0)
            cnt += 2;
    if (i * i == n)
        cnt++;
    cout << cnt << "\n";
    return 0;
}
