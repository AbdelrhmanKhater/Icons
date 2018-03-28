#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
bool val = true, existed = false;
int H[9], H1[9], H2[9], H3[9];

bool checkExist(int index) {
	for (int i = 0; i<9; i++)
		if (H[i] == index)
			return true;
	return false;
}
bool checkExist1(int index) {
	for (int i = 0; i<9; i++)
		if (H1[i] == index)
			return true;
	return false;
}
bool checkExist2(int index) {
	for (int i = 0; i<9; i++)
		if (H2[i] == index)
			return true;
	return false;
}
bool checkExist3(int index) {
	for (int i = 0; i<9; i++)
		if (H3[i] == index)
			return true;
	return false;
}
int main() {
	int t, o, r, d, w;
	string kol[9] = { "  ","Russia","France" ,"Portugal","Germany","Belgium","Poland","Brazil","Argentine" };
	string b[9] = { "  ","Mexico","Uruguay","Peru","Colombia","England","Spain","Switzerland","Croatia" };
	string e[9] = { "  ","Egypt","Senegal","Tunisia","Iran","Costa_Rica","Iceland","Swide","Denmark" };
	string g[9] = { "  ","Moroco","Nigere","South_Korea","Jaban","Saudi_Arabia","Australia","Panama","Serbia" };
	srand(time(0));
	t = rand() % 8;
	o = rand() % 8;
	r = rand() % 8;
	d = rand() % 8;
	for (int k = 1;k <= 8;k++)
	{
		t = rand() % 9;
		while (checkExist(t)) {
			t = rand() % 9;
		}
		H[k] = t;
		o = rand() % 9;
		while (checkExist1(o)) {
			o = rand() % 9;
		}
		H1[k] = o;
		r = rand() % 9;
		while (checkExist2(r)) {
			r = rand() % 9;
		}
		H2[k] = r;
		d = rand() % 9;
		while (checkExist3(d)) {
			d = rand() % 9;
		}
		H3[k] = d;
		fstream file;
		file.open("worldCup.txt");
		file << "Group" << k << "  " << kol[t] << "  " << b[o] << "   " << e[r] << "  " << g[d] << endl;
		file.close();
	}
	cout << "File was succsefully written" << endl;

	system("pause");
}
