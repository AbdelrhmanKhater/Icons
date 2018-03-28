#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <stdio.h>

using namespace std;
struct book
{
    int t, sze;
    string tp[25];
};
set<string> nop;
int memo[105][25];
int b, mx;
set<int> ans;
book books[105];
string x;
int v = 0;
map <string, int> vis;
int Count_Book(int idx)
{
    int ret = 0;
    for (int i = 0; i < books[idx].sze; i++)
        vis[books[idx].tp[i]]++;
    //return mx - count(vis.begin(), vis.end(), 0);
    set<string>::iterator it = nop.begin();
    while(it != nop.end())
    {
        if (vis[*it] != 0)
            ret++;
        it++;
    }
    return ret;
}
void Remove_Book(int idx)
{
    for (int i = 0; i < books[idx].sze; i++)
        vis[books[idx].tp[i]]--;
}
void Rec_Solve(int idx, int ntp, int val)
{
    int ret = 0;
    if (*(ans.begin()) < ntp)
        return;
    if (ntp >= mx || idx == b)
        {
            if(ntp == mx)
                ans.insert(val);
            return;
        }
    /*if (idx == b && ntp < mx)
        return 1000000000;
    if (memo[idx][ntp] != -1)
        return memo[idx][ntp];*/
    int k = Count_Book(idx);
    Rec_Solve(idx + 1, k, books[idx].t + val);
    Remove_Book(idx);
    Rec_Solve(idx + 1, ntp, val);
    //return memo[idx][ntp] = ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    memset(memo, -1, sizeof memo);
    int idx = 0;
    while(getline(cin,x))
    {
        b++;
        idx = 0;
        stringstream s(x);
        s >> books[b-1].t;
        while (s >> books[b-1].tp[idx++]);
        books[b-1].sze = idx;
        for (int j = 0; j < idx; j++)
            nop.insert(books[b-1].tp[j]);
    }
    mx = nop.size();
    set<string>::iterator it = nop.begin();
    while(it != nop.end())
    {
        vis[*it] = 0;
        it++;
    }
    ans.insert(100000000);
    Rec_Solve(0, 0, 0);
    /*int mn = ans[0];
    for (int i = 1; i < vis.size(); i++)
        if (mn > ans[i])
            mn = ans[i];
    cout << mn << "\n";*/
    cout << *ans.begin();
    return 0;
}
