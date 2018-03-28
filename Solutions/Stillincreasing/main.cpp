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
#include <stdio.h>

using namespace std;
int n;
int nums[55];
void Shift_Move(int s, int val, int sht)
{
    nums[s] = val;
    int cnt = 1;
    for (int i = sht + 1; i < n; i++)
    {
        nums[s+ cnt] = nums[i];
        cnt++;
    }
}
void Greedy_Solve()
{
    int cnt = 0, k = 0, last;
    for (int i = n - 2; i > 0; i--)
    {
        last = i;
        long long sum = nums[i];
        bool f = false;
        for (int j = i - 1; j > -1; j--)
           {
               i = j + 1;
               if (sum + nums[j] < nums[last + 1])
                {
                    cnt++;
                    sum += nums[j];
                    f = true;
                }
                else
                {
                    if(f)
                        Shift_Move(j + 1, sum, last);
                    break;
                }

           }
    }
    cout << cnt << "\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Greedy_Solve();
    return 0;
}
