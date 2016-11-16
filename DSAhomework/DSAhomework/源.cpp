#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int n, m;
int d[100005];
vector<int>e[100005];
priority_queue<int, vector<int>, greater<int> >s;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		d[v]++;
	}
	for (int i = 1; i <= n; i++)
		if (!d[i])
			s.push(i);
	while (!s.empty())
	{
		int x = s.top(); 
		s.pop();
		printf("v%d ", x);
		for (int i = 0; i < e[x].size(); i++)
		{
			int t = e[x][i];
			d[t]--;
			if (!d[t])
				s.push(t);
		}
	}
	system("pause");
	return 0;
}