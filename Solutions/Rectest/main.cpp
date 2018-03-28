#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int nums[5],memo[5];
int solve(int idx)
{
    int ret = 1e9;
    if (memo[idx] != -1)
        return memo[idx];
    for (int i = idx; i < 4; i++)
        ret = min(ret,min(nums[idx] + nums[i + 1], solve(i + 1)));
    return memo[idx] = ret;
}
int main()
{
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < 5; cin >> nums[i++]);
    cout << solve(0);
    return 0;
}
