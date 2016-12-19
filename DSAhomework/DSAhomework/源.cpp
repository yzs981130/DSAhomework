#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 1200;
map<string, set<int> > dic;
int main()
{
	int n, m, c;
	string s;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> c;
		for (int j = 0; j < c; j++)
		{
			cin >> s;
			set<int> tmp = dic[s];
			tmp.insert(i);
			dic[s] = tmp;
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		set<int>ans = dic[s];
		if (!ans.empty())
		{
			set<int>::iterator itr = ans.begin();
			for (; itr != ans.end(); ++itr)
				cout << (*itr) << ' ';
		}
		else
			cout << "NOT FOUND";
		cout << endl;
	}
	system("pause");
	return 0;
}