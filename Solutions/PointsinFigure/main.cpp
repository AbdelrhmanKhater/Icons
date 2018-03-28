#include <bits/stdc++.h>

using namespace std;
struct Rectangle
{
    double xu, yu , xl, yl;
};
vector<Rectangle> rect;
Rectangle cur;
bool f = true;
char c;
double xu, yu, xl, yl;
bool Check(double x, double y, int idx)
{
    return ((x > rect[idx].xu) && (y < rect[idx].yu) && (x < rect[idx].xl) && (y > rect[idx].yl));
}
int lvl = 0;
int main()
{
    while (cin >> c && c == 'r')
    {
        cin >> cur.xu >> cur.yu >> cur.xl >> cur.yl;
        rect.push_back(cur);
    }
    while (cin >> xu >> yu && (xu != 9999.9 || yu!= 9999.9))
    {
        lvl++;
        f = true;
        for (int i = 0; i < rect.size(); i++)
        {
            if (Check(xu, yu, i))
            {
                cout << "Point " << lvl << " is contained in figure " << i + 1<< "\n";
                f = false;
            }
        }
        if (f)
            cout << "Point " << lvl << " is not contained in any figure\n";
    }
    return 0;
}
