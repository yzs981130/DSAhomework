#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
#define MAXN 30010
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
	int fx = find(x), fy = find(y);
	if (fx == fy)
		return;
	p[fx] = fy;
}
int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) && n != 0)
	{
		int k;
		for (int i = 0; i < n; i++)
			p[i] = i;
		int t;
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &k);
			if (!k)
				continue;
			scanf("%d", &t);
			int r;
			for (int i = 1; i < k; i++)
			{
				scanf("%d", &r);
				unite(r, t);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (find(i) == find(0))
				ans++;
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}