#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int v1, v2;
};
Node cur, tmp;
queue<Node> g;
map<pair<int, int>, pair<int, int> > lev;
//vector<int> lev[40005];
int a, b, c, rem, t;
int siz[2], pour[2], siz_g;
int BFS()
{
    cur.v1 = 0;
    cur.v2 = 0;
    int i = 0;
    g.push(cur);
    while (g.size())
    {
        siz_g = g.size();
        while (siz_g--)
        {
            cur = g.front();
            g.pop();
            if ((lev.count(make_pair(cur.v1, cur.v2)) != 0 && lev[make_pair(cur.v1, cur.v2)].second == t))
                continue;
            lev[make_pair(cur.v1, cur.v2)] = {i, t};
            if (cur.v1 == c || cur.v2 == c)
                return i;
            if (cur.v1 == 0)
            {
                tmp.v1 = a;
                tmp.v2 = cur.v2;
                g.push(tmp);
            }
            if (cur.v2 == 0)
            {
                tmp.v1 = cur.v1;
                tmp.v2 = b;
                g.push(tmp);
            }
            if (cur.v1 == a)
            {
                tmp.v1 = 0;
                tmp.v2 = cur.v2;
                g.push(tmp);
            }
            if (cur.v2 == b)
            {
                tmp.v1 = cur.v1;
                tmp.v2 = 0;
                g.push(tmp);
            }
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                {
                    pour[0] = cur.v1, pour[1] = cur.v2;
                    if (j == k) continue;
                    rem = siz[j] - pour[j];
                    if (rem >= pour[k])
                    {
                        pour[j] = pour[j] + pour[k];
                        pour[k] = 0;
                    }
                    else
                    {
                        pour[j] += rem;
                        pour[k] -= rem;
                    }
                    tmp.v1 = pour[0];
                    tmp.v2 = pour[1];
                    g.push(tmp);
                }
        }
        i++;
    }
}
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
int check(int a,int b) {

    int ret = 0,ca = 0,cb = 0;

    for (;;) {

        if (ca==c || cb==c) return ret;

        if (cb==b) cb = 0;

        else if (ca==0) ca = a;

        else {

            int dt = min(b-cb,ca);

            ca -= dt; cb += dt;

        }

        ret++;

    }

}
int main()
{
    ios::sync_with_stdio(false);
    //cin >> t;
    //while (t--)
    t = 1;
    while (true)
    {
        a = rand() % 40000 + 1;
        b = rand() % 40000 + 1;
        c = rand() % 40000;
        lev.clear();
       // cin >> a >> b >> c;
        cout << a << " " << b << " " << c << endl;
        int len = max(a, b) + 8;
        while(g.size())
            g.pop();
        /*for (int i = 0; i <= len; i++)
            lev[i].resize(len + 5);
        for (int i = 0; i <= len; i++)
            for (int j = 0; j <= len; j++)
                lev[i][j] = -1;*/
        siz[0] = a, siz[1] = b;
        if (c % GCD(a, b))
            cout << "-1\n";
        else if (c > a && c > b)
            cout << "-1\n";
        else
            {
                int res1 = BFS();
                int res2 = min(check(a,b), check(b, a));
                if (res1 == res2)
                    cout << "Ok\n";
                else
                {
                    cout << res1 << " " << res2 << "\n";
                    break;
                }

            }
            t++;
    }
    return 0;
}
