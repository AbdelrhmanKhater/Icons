#include <bits/stdc++.h>

using namespace std;
int t, xl, xl1, xl2, yl, yl1, yl2, xu, xu1, xu2, yu, yu1, yu2;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> xl1 >> yl1 >> xu1 >> yu1;
        cin >> xl2 >> yl2 >> xu2 >> yu2;
        xl = max(xl1, xl2);
        xu = min(xu1, xu2);
        yl = max(yl1, yl2);
        yu = min(yu1, yu2);
        if (xl < xu && yl < yu)
            cout << xl << " " << yl << " " << xu << " " << yu << "\n";
        else
            cout << "No Overlap\n";
        if (t)
            cout << "\n";
    }
    return 0;
}
