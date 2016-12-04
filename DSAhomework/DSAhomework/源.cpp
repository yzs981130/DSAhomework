#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
	map<string, int> m;
	map<string, int>::iterator pr;
	string s;
	int num = 0;
	while (getline(cin, s))
	{
		num++;
		m[s]++;
	}
	for (pr = m.begin(); pr != m.end(); pr++)
		cout << pr->first << " " << fixed << setprecision(4) << (double)pr->second / num * 100.0 << endl;
	system("pause");
	return 0;
}