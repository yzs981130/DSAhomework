#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <stack>
#include <bitset>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 310
using namespace std;
int p[MAXN];
int a[MAXN][MAXN];
int find(int x)
{
	if (x == p[x])
		return x;
	p[x] = find(p[x]);
	return p[x];
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
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			char c = getchar();
			if (c == '\n')
				c = getchar();
			if (c - '0')
				unite(i, j);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (find(i) == find(j))
				cout << 1;
			else
				cout << 0;
			if (j == n - 1)
				cout << endl;
		}
	return 0;
}