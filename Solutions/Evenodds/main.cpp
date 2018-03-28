#include <bits/stdc++.h>

using namespace std;
long long n, k;
long long siz;
int main()
{
    cin >> n >> k;
    siz = ceil(n / 2.0);
    if (k <= siz)
        cout << 2 * k - 1 << "\n";
    else
        cout << 2 * (k - siz) << "\n";
    return 0;
}
