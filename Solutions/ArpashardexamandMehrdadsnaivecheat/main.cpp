#include <iostream>

using namespace std;
int adhoc[4] = {6, 8, 4, 2};
int n;
int main()
{
    cin >> n;
    if (n == 0)
        cout << "1\n";
    else
        cout << adhoc[n % 4] << "\n";
    return 0;
}
