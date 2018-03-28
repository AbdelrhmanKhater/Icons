#include <bits/stdc++.h>

using namespace std;
int n, num[100005];
bool Is_Small(int s, int e, int key)
{
    if (s > e)
        return false;
    int mid = (s + e) / 2;
    if (num[mid] < key)
        return true;
    return Is_Small(s, mid - 1, key);
}
bool Is_Big(int s, int e, int key)
{
    if (s > e)
        return false;
    int mid = (s + e) / 2;
    if (num[mid] > key)
        return true;
    return Is_Big(mid + 1, e, key);
}
void Merge(int s, int mid, int e)
{
    int n1 = mid - s + 1, n2 = e - mid;
    int num1[n1], num2[n2];
    for (int i = 0; i < n1; i++)
        num1[i] = num[s + i];
    for (int i = 0; i < n2; i++)
        num2[i] = num[mid + 1 + i];
    int i = 0, j = 0, siz = s;
    while (i < n1 && j < n2)
        if (num1[i] < num2[j])
            num[siz++] = num1[i++];
        else
            num[siz++] = num2[j++];
    while (i < n1)
        num[siz++] = num1[i++];
    while (i < n2)
        num[siz++] = num2[j++];
}
void Merge_Sort(int s, int e)
{
    if (s == e)
        return;
    int mid = (s + e) / 2;
    Merge_Sort(s, mid);
    Merge_Sort(mid + 1, e);
    Merge(s, mid, e);
}
void Greedy_Solve()
{
    int cnt = 0;
    for (int i = 1; i < n - 1; i++)
        if (Is_Small(0, n - 1, num[i]) && Is_Big(0, n - 1, num[i]))
            cnt++;
    cout << cnt << "\n";
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    Merge_Sort(0, n - 1);
    Greedy_Solve();
    return 0;
}
