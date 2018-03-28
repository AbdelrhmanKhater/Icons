#include <iostream>

using namespace std;

int n;
long long num;
bool flag = true;
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num % 2)
            flag = false;
    }
    if (flag)
        cout << "Second\n";
    else
        cout << "First\n";
    return 0;
}