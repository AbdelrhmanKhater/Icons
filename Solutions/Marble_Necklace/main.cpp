#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<bits/stdc++.h>

using namespace std;


class MarbleNecklace {
public:
    string necklaces[105];
    string Greedy_Solve(string necklace)
    {
        int len = necklace.length();
        necklaces[0] = necklace;
        for (int i = 1; i < len; i++)
            necklaces[i] = necklaces[i - 1][len - 1] + necklaces[i - 1].substr(0, len - 1);
        reverse(necklace.begin() , necklace.end());
        necklaces[len] = necklace;
        for (int i = 1; i < len; i++)
            necklaces[len + i] = necklaces[len + i - 1][len - 1] + necklaces[len + i - 1].substr(0, len - 1);
        sort(necklaces + 1, necklaces + (2 * len ));
        return necklaces[1];
    }
	string normalize(string necklace) {
		return Greedy_Solve(necklace);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	MarbleNecklace *obj;
	string answer;
	obj = new MarbleNecklace();
	clock_t startTime = clock();
	answer = obj->normalize(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	string p0;
	string p1;

	{
	// ----- test 0 -----
	p0 = "CDAB";
	p1 = "ABCD";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = "RGB";
	p1 = "BGR";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = "TOPCODER";
	p1 = "CODERTOP";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = "SONBZELGFEQMSULZCNPJODOWPEWLHJFOEW";
	p1 = "BNOSWEOFJHLWEPWODOJPNCZLUSMQEFGLEZ";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!