#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#define MAX 1200  
using namespace std;
bool map[MAX][MAX], used[MAX];
int mat[MAX];
int p[MAX][MAX];
int dir[8] = { 1,0,-1,0,0,1,0,-1 };
void BFS(int n, int m)
{
	int i, k, q;
	for (i = 1; i <= n; i++)
		for (k = 1; k <= m; k++)
		{
			if (p[i][k] == -1)
				continue;
			for (q = 0; q < 8; q += 2)
			{
				int a = i + dir[q];
				int b = k + dir[q + 1];
				if (p[a][b] != -1 && a >= 1 && b <= m && a <= n && b >= 1)
					map[p[i][k]][p[a][b]] = true;
			}
		}
}
int Augment(int x, int n)
{
	int i;
	for (i = 1; i <= n; i++)
		if (!used[i] && map[x][i])
		{
			used[i] = true;
			if (!mat[i] || Augment(mat[i], n))
			{
				mat[i] = x;
				return 1;
			}
		}
	return 0;
}
int Hungary(int n, int m)
{
	int i, sum = 0;
	memset(mat, 0, sizeof(mat));
	for (i = 1; i <= n; i++)
	{
		memset(used, false, sizeof(used));
		if (Augment(i, m))
			sum++;
	}
	return sum;
}
int main()
{
	int n, m, k, i, x, y, tmp;
	while (~scanf("%d%d%d", &n, &m, &k))
	{
		memset(p, 0, sizeof(p));
		memset(map, false, sizeof(map));
		tmp = k;
		for (i = 1; i <= k; i++)
		{
			scanf("%d%d", &x, &y);
			p[y][x] = -1;
		}
		if (n*m % 2 != k % 2)
		{
			printf("NO\n");
			continue;
		}

		int ind = 1;
		for (i = 1; i <= n; i++)
			for (k = 1; k <= m; k++)
				if (p[i][k] == 0)
					p[i][k] = ind++;
		BFS(n, m);
		int ans = Hungary(ind - 1, ind - 1);
		if (ans / 2 == (n*m - tmp) / 2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}