#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 205
int graph[MAXN][MAXN];
int match[MAXN];
int book[MAXN];
int n, m, p;
vector<int>e[MAXN];
bool dfs(int u) 
{
	for (int i = 0; i < e[u].size(); i++)
	{
		int v = e[u][i];
		if (!book[v])
		{
			book[v] = true;
			if (match[v] == 0 || dfs(match[v]))
			{
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}
int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) 
	{
		scanf("%d %d", &p, &n);
		if (p > n)
		{
			printf("NO\n");
			continue;
		}
		memset(match, 0, sizeof(match));
		memset(e, 0, sizeof(e));
		int s, k;
		for (int i = 1; i <= p; i++) 
		{
			scanf("%d", &s);
			for (int j = 0; j < s; j++)
			{
				scanf("%d", &k);
				e[i].push_back(k);
			}
		}
		bool ans = true;
		for (int i = 1; i <= p; i++) 
		{
			memset(book, 0, sizeof(book));
			if (!dfs(i))
			{
				ans = false;
				break;
			}
		}
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	system("pause");
	return 0;
}