#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
//int nums[4] = {2, 3, 5, 7};
//int nums[4] = {2, 3, 8, 10};
int nums[2] = {2, 3};
int n = 100;
/*int Brute_Force(int idx, string str)
{
    int ret = 0;
    if (idx == 4)
    {
       int cnt_s = 0, sign = -1, d = 1;
       for (int i = 0; i < 4; i++)
           if (str[i] == '1')
           {
              cnt_s++;
              d *= nums[i];
           }
      if (!cnt_s)
         return 0;
      if (cnt_s % 2)
         sign = 1;
      ret = sign * (100 - (n / d));
      return ret;
      }
      ret = Brute_Force(idx + 1, str + '1');
      ret += Brute_Force(idx + 1, str + '0');
      return ret;
}*/
int GCD(int a, int b)
{
    if (b == 0)
       return a;
    return GCD(b, a % b);
}
int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}
/*int Brute_Force(int idx, int lcm, int sign)
{
    int ret = 0;
    if (idx == 4)
    {
       if (lcm == 1)
          return ret;
       ret = sign * (n / lcm);
       return ret;
    }
    ret = Brute_Force(idx + 1, LCM(lcm, nums[idx]), -1 * sign);
    ret += Brute_Force(idx + 1, lcm, sign);
    return ret;
}*/
int Brute_Force(int idx, int lcm, int sign)
{
    int ret = 0;
    if (idx == 2)
    {
       if (lcm == 1)
          return ret;
       ret = sign * (n / lcm);
       return ret;
    }
    ret = Brute_Force(idx + 1, LCM(lcm, nums[idx]), -1 * sign);
    ret += Brute_Force(idx + 1, lcm, sign);
    return ret;
}
int main()
{
    cout << Brute_Force(0, 1, -1) << "\n";
    return 0;
}
