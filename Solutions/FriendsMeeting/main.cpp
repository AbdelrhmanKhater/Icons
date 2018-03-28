#include <bits/stdc++.h>

using namespace std;
float steps, a, b;
int ff = 0, sf = 0;
int cnt1, cnt2;
int main()
{
    cin >> a >> b;
    steps = abs(a - b);
    cnt1 = ceil(steps / 2);
    cnt2 = steps / 2;
    ff = (cnt1 * (cnt1 + 1)) / 2;
    sf = (cnt2 * (cnt2 + 1)) / 2;
    cout << ff + sf << "\n";
    return 0;
}
