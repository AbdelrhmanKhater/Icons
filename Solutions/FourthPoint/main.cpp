#include <bits/stdc++.h>

using namespace std;

set<pair<double, double> > pt;
double xmid, ymid;
double pts[2][2];
double x, y;
map<pair<double, double>, int> vis;
int lvl = 0;
int main()
{
    while (cin >> x >> y)
    {
        lvl = 0;
        pt.clear();
        vis.clear();
        pt.insert(make_pair(x, y));
        vis[make_pair(x, y)] = 1;
        for (int i = 0; i < 3; i++)
        {
            cin >> x >> y;
            if (vis.count(make_pair(x, y)) != 0)
            {
                xmid = x;
                ymid = y;
                pt.erase(pt.find(make_pair(xmid, ymid)));
            }
            else
            {
                vis[make_pair(x, y)] = 1;
                pt.insert(make_pair(x, y));
            }
        }
        while (pt.size())
        {
            pair<double, double> cur = *pt.begin();
            pt.erase(pt.begin());
            pts[lvl][0] = cur.first;
            pts[lvl][1] = cur.second;
            lvl++;
        }
    cout << fixed << setprecision(3) << pts[1][0] + pts[0][0] - xmid << " " << pts[0][1] + pts[1][1] - ymid << "\n";
    }

    return 0;
}
