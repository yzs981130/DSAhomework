#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 100010
int p[MAXN], AB[MAXN];
int find(int x)
{
	return p[x] == x ? x : (p[x] = find(p[x]));
}
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	p[x] = y;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int a, b;
		for (int i = 1; i <= n; i++) 
		{
			p[i] = i;
			AB[i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			char c;
			cin >> c;
			if (c == 'D')
			{
				cin >> a >> b;
				if (AB[a] == 0 && AB[b] == 0)
					AB[a] = b, AB[b] = a;
				else if (AB[a] == 0) 
				{
					AB[a] = b;
					unite(a, AB[b]);
				}
				else if (AB[b] == 0) 
				{
					AB[b] = a;
					unite(b, AB[a]);
				}
				else 
				{
					unite(a, AB[b]);
					unite(b, AB[a]);
				}
			}
			else
			{
				cin >> a >> b;
				if (find(a) == find(b))
					printf("In the same gang.\n");
				else if (find(a) == find(AB[b]))
					printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			}
		}
	}
	system("pause");
	return 0;
}