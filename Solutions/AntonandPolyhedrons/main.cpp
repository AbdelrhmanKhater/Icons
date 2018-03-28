#include <bits/stdc++.h>

using namespace std;

map<string, int> shape;
int n;
string x;
int res = 0;
int main()
{
    shape["Tetrahedron"] = 4;
    shape["Cube"] = 6;
    shape["Octahedron"] = 8;
    shape["Dodecahedron"] = 12;
    shape["Icosahedron"] = 20;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        res += shape[x];
    }
    cout << res << '\n';
    return 0;
}
