#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
struct data 
{
	int l, r, num, rnd, s;
}tr[100001];
int n, mn;
int root, Size, leave, delta;
void update(int k) { tr[k].s = tr[tr[k].l].s + tr[tr[k].r].s + 1; }
void rturn(int &k)
{
	int t = tr[k].l;
	tr[k].l = tr[t].r;
	tr[t].r = k;
	tr[t].s = tr[k].s;
	update(k);
	k = t;
}
void lturn(int &k)
{
	int t = tr[k].r;
	tr[k].r = tr[t].l;
	tr[t].l = k;
	tr[t].s = tr[k].s;
	update(k);
	k = t;
}
void insert(int &k, int x)
{
	if (k == 0)
	{
		Size++; k = Size;
		tr[k].rnd = rand();
		tr[k].num = x;
		tr[k].s = 1;
		return;
	}
	tr[k].s++;
	if (x<tr[k].num)
	{
		insert(tr[k].l, x);
		if (tr[tr[k].l].rnd<tr[k].rnd)rturn(k);
	}
	else
	{
		insert(tr[k].r, x);
		if (tr[tr[k].r].rnd<tr[k].rnd)lturn(k);
	}
}
int del(int &k, int x)
{
	int t;
	if (k == 0)return 0;
	if (tr[k].num<x)
	{
		t = tr[tr[k].l].s + 1; k = tr[k].r; return t + del(k, x);
	}
	else { t = del(tr[k].l, x); tr[k].s -= t; return t; }
}
int find(int k, int x)
{
	if (tr[tr[k].l].s + 1 == x)return tr[k].num + delta;
	else if (tr[tr[k].l].s + 1<x)return find(tr[k].r, x - tr[tr[k].l].s - 1);
	else return find(tr[k].l, x);
}
int main()
{
	scanf("%d%d", &n, &mn);
	char ch; int x;
	while (n--)
	{
		scanf("%c %d\n", &ch, &x);
		if (ch == 'I')if (x >= mn)insert(root, x - delta);
		if (ch == 'A')delta += x;
		if (ch == 'S') { delta -= x; leave += del(root, mn - delta); }
		if (ch == 'F')
		{
			if (x>tr[root].s)printf("-1");
			else printf("%d", find(root, tr[root].s - x + 1));
			printf("\n");
		}
	}
	printf("%d", leave);
	system("pause");
	return 0;
}