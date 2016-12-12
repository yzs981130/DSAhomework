#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXM 500010
#define MAXN 100010
vector<int>e[MAXN];
int d[MAXN];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, x, y;
		memset(e, 0, sizeof(e));
		memset(d, 0, sizeof(d));
		stack<int>s;
		cin >> n >> m;
		int cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d", &x, &y);
			e[x].push_back(y);
			d[y]++;
		}
		for (int i = 1; i <= n; i++)
			if (!d[i])
				s.push(i);
		while (!s.empty())
		{
			int t = s.top();
			s.pop();
			cnt++;
			for (int i = 0; i < e[t].size(); i++)
			{
				int r = e[t][i];
				d[r]--;
				if (!d[r])
					s.push(r);
			}
		}
		cout << ((cnt == n) ? "No" : "Yes") << endl;
	}
	return 0;
}