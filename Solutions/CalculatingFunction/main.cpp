#include<bits/stdc++.h>

using namespace std;
long long n;
int main()
{
    cin >> n;
    if (n % 2)
        cout << -1 * (n - 1) / 2 - 1 << "\n";
    else
        cout << fixed << setprecision(0) << n / 2 << "\n";
    return 0;
}
