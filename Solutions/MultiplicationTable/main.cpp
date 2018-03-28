#include <bits/stdc++.h>

using namespace std;
int n, x;
int main()
{
    cin >> n >> x;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (x % i == 0 && (x / i) <= n)
            cnt++;
    cout << cnt << "\n";
    return 0;
}
