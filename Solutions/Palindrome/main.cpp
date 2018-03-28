#include <iostream>
#include <iostream>

using namespace std;

string x;
bool isPalindorme(int s, int e)
{
    if (s > e)
        return true;
    if (x[s] != x[e])
        return false;
    return isPalindorme(s + 1, e - 1);
}
int main()
{
    cin >> x;
    if(isPalindorme(0, x.size() - 1))
        cout << "It is palindrome\n";
    else
        cout << "It isn't palindrome";
    return 0;
}
