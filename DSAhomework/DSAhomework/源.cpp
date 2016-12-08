#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;
#define MAXN 30
#define INFI 99999
bool flag[MAXN];
struct Edge
{
	int a, b;
	int weight;
}edge[200];
int cmp(Edge a, Edge b)
{
	return a.weight < b.weight;
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	while (cin >> n && n != 0)
	{
		memset(edge, 0, sizeof(edge));
		memset(flag, 0, sizeof(flag));
		int cnt_edge = 0;
		for (int i = 0; i < n - 1; i++)
		{
			char c;
			int cnt;
			cin >> c >> cnt;
			for (int j = 0; j < cnt; j++)
			{
				char d;
				int len;
				cin >> d >> len;
				edge[cnt_edge].a = c - 'A';
				edge[cnt_edge].b = d - 'A';
				edge[cnt_edge].weight = len;
				cnt_edge++;
			}
		}
		sort(edge, edge + cnt_edge, cmp);
		int ans = 0, left = n - 1;
		flag[0] = true;
		while (left != 0)
		{
			for (int i = 0; i < cnt_edge; i++)
			{
				if (flag[edge[i].a] && flag[edge[i].b] || !flag[edge[i].a] && !flag[edge[i].b])
					continue;
				if (flag[edge[i].a] && !flag[edge[i].b])
					flag[edge[i].b] = true;
				else if (flag[edge[i].b] && !flag[edge[i].a])
					flag[edge[i].a] = true;
				ans += edge[i].weight;
				left--;
				i = -1;
			}
		}
		cout << ans << endl;
	}
	//system("pause");
	return 0;
}