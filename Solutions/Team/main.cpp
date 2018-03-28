#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;

int n, x1, x2, x3, cnt = 0;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> x2 >> x3;
        if (x1 + x2 + x3 > 1)
            cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
