#include <bits/stdc++.h>

using namespace std;
int cum[100005], n;
int w[1000005];
int q, num;
int Binary_Solve(int s, int e, int val)
{
    if (s > e)
        return s;
    int mid = (s + e) / 2;
    if (cum[mid] == val)
        return mid;
    else if (cum[mid] > val)
        return Binary_Solve(s, mid - 1, val);
    return Binary_Solve(mid + 1, e, val);
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> cum[i];
        //cum[i] += cum[i - 1];
    }
    for (int i = 1, j= 1; i <= n; ++i)
        while(cum[i]--)
            w[j++] =i;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> num;
        cout << w[num] << "\n";
        //cout << Binary_Solve(1, n, num) << "\n";
    }


    return 0;
}
