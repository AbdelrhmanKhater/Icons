#include <bits/stdc++.h>

using namespace std;
long long r, c, flag;
long long Maths_Solve()
{
    long long nc = c - 7, nr = r - 7;
    if ((nc % 2) && (nr % 2))
        if (flag)
        {
            long long t1 = (ceil(nc / 2.0) * ceil(nr / 2.0));
            long long t2 = (floor(nc / 2.0) * floor(nr / 2.0));
            return t1 + t2;
            cout << t1 + t2 << "\n";
        }
        else
        {
            long long t1 = (floor(nc / 2.0) * ceil(nr / 2.0));
            long long t2 = (ceil(nc / 2.0) * floor (nr / 2.0));
            return t1 + t2;
            cout << t1 + t2 << "\n";
        }

    else
        return (nc * nr) / 2;
        cout << (nc * nr) / 2 << "\n";
}
long long Maths_Solve2()
{
    if (flag == 0)
        return (r-7)*(c-7)/2;
    return ((r-7)*(c-7)+1)/2;

}
int main()
{
    ios::sync_with_stdio(false);
    /*while (true)
    {
        r = rand() % 40000 + 8;
        c = rand() % 40000 + 8;
        flag = rand() % 2;
        cout << r << " " << c << " " << flag << endl;
        int res1 = Maths_Solve();
        int res2 = Maths_Solve2();
        if (res1 == res2)
            cout << "Ok\n";
        else
        {
          cout << res1 << " " << res2 << endl;
          break;
        }
    }*/
    while (cin >> r >> c >> flag && r != 0)
       cout << Maths_Solve() << "\n";
    return 0;
}
