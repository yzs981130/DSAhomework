#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std;
#define MAXN 1010
int d[MAXN];
int p[MAXN];
int find(int x)
{
	while (x != p[x])
	{
		p[x] = p[p[x]];
		x = p[x];
	}
	return x;
}
void unite(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
		p[fx] = fy;
}
int main()
{
	int n, m, a, b;
	while (cin >> n && n != 0)
	{
		memset(d, 0, sizeof(d));
		for (int i = 0; i < n; i++)
			p[i] = i;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			unite(a, b);
			d[a]++;
			d[b]++;
		}
		bool ans = true;
		for (int i = 0; i < n; i++)
			if (d[i] % 2 || find(i) != find(0))
			{
				ans = false;
				break;
			}

		cout << ans << endl;
	}
	return 0;
}