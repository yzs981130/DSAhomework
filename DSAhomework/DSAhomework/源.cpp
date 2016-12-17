#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 205
int graph[maxn][maxn];
int match[maxn];
int book[maxn];
int n, m, k;
bool dfs(int u) 
{
	for (int i = 1; i <= n; i++) 
	{
		if (book[i] == 0 && graph[i][u] == 1) 
		{
			book[i] = 1;
			if (match[i] == 0 || dfs(match[i])) 
			{
				match[i] = u;
				return 1;
			}
		}
	}
	return 0;
}
int main() 
{
	int cnt = 0;
	while (scanf("%d %d", &m, &n) != EOF) 
	{
		memset(graph, 0, sizeof(graph));
		memset(match, 0, sizeof(match));
		
		int s, k;
		for (int i = 1; i <= m; i++) 
		{
			scanf("%d", &s);
			for (int j = 0; j < s; j++)
			{
				scanf("%d", &k);
				graph[i][k] = 1;
			}
		}
		int sum = 0;
		for (int i = 1; i <= m; i++) 
		{
			memset(book, 0, sizeof(book));
			if (dfs(i))
				sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}