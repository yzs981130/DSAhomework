#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#define MAXN 50010
#define INF 99999999
using namespace std;
struct node
{
	int w, fa, lch, rch;
	char s[111];
	bool operator <(const node& a)const
	{
		return strcmp(s, a.s) <= 0;
	}
}p[MAXN];
int n;
void insert(int i)
{
	int j = i - 1;
	while (p[j].w < p[i].w) 
		j = p[j].fa;
	p[i].lch = p[j].rch;
	p[j].rch = i;
	p[i].fa = j;
}
void solve(int rt)
{
	if (rt == 0) 
		return;
	printf("(");
	solve(p[rt].lch);
	printf("%s/%d", p[rt].s, p[rt].w);
	solve(p[rt].rch);
	printf(")");
}
int main()
{
	char s[111], tmp[111];
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf(" %[a-z]/%d", p[i].s, &p[i].w);
			p[i].lch = p[i].rch = 0;
			p[i].fa = 0;
		}
		sort(p + 1, p + n + 1);
		p[0].w = INF;
		p[0].lch = p[0].rch = p[0].fa = 0;
		for (int i = 1; i <= n; i++) insert(i);
		solve(p[0].rch);
		printf("\n");
	}
	return 0;
}
