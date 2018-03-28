#include <bits/stdc++.h>

using namespace std;
int n, num[50005];
int q, key;
int Binary_Small(int s, int e, int val)
{
    if (s > e)
        return e;
    int mid = (s + e) / 2;
    if (num[mid] < val)
        return Binary_Small(mid + 1, e, val);
    else
        return Binary_Small(s, mid - 1, val);
}
int Binary_Big(int s, int e, int val)
{
    if (s > e)
        return s;
    int mid = (s + e) / 2;
    if (num[mid] > val)
        return Binary_Big(s, mid - 1, val);
    else
        return Binary_Big(mid + 1, e, val);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> key;
        if (Binary_Small(0, n - 1, key) != -1)
            cout << num[Binary_Small(0, n - 1, key)] << " ";
        else
            cout << "X ";
        if (Binary_Big(0, n - 1, key) != n)
            cout << num[Binary_Big(0, n - 1, key)] << "\n";
        else
            cout << "X\n";
    }

    return 0;
}
