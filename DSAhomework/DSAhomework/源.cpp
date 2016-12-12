#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <functional>
#include <queue>
#include <cstdio>
#define MAXN 50010
using namespace std;
int a[MAXN];
priority_queue<int, vector<int> >big;
priority_queue<int, vector<int>, greater<int> >small;
int cnt = 0;
struct Node
{
	int v, w;
	int s;
	Node *son[2];
	void Resize()
	{
		s = 1;
		if (son[0])
			s += son[0]->s;
		if (son[1])
			s += son[1]->s;
	}
}nodes[MAXN];
void Rotate(Node *&p, int d)
{
	Node *u = p->son[d];
	p->son[d] = u->son[d ^ 1];
	u->son[d ^ 1] = p;
	p->Resize();
	u->Resize();
	p = u;
}
void Insert(Node *&p, int v)
{
	if (p == NULL)
	{
		nodes[cnt].s = 1;
		nodes[cnt].son[0] = NULL;
		nodes[cnt].son[1] = NULL;
		nodes[cnt].v = v;
		nodes[cnt].w = rand();
		p = &nodes[cnt];
		cnt++;
	}
	else
	{
		int d = (v > p->v) ? 1 : 0;
		Insert(p->son[d], v);
		if (p->son[d]->w > p->w)
			Rotate(p, d);
	}
	p->Resize();
}
void Remove(Node *&p, int v)
{
	if (p->v == v)
	{
		if (p->son[0] && p->son[1])
		{
			int d = (p->son[0]->w < p->son[1]->w) ? 1 : 0;
			Rotate(p, d);
			Remove(p->son[d ^ 1], v);
		}
		else
		{
			Node *u = p;
			if (p->son[0] == NULL)
				p = p->son[1];
			else
				p = p->son[0];
			delete u;
		}
	}
	else
		Remove(p->son[v > p->v], v);
	if (p)
		p->Resize();
}
int Find(Node *p, int v)
{
	int ls = (p->son[0]) ? p->son[0]->s : 0;
	if (v == ls + 1)
		return p->v;
	else if (v < ls + 1)
		return Find(p->son[0], v);
	else
		return Find(p->son[1], v - ls - 1);
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	Node *root = NULL;
	int j = 0;
	for (int i = 0; i < m; i++)
	{
		int t;
		scanf("%d", &t);
		for (; j < t; j++)
			Insert(root, a[j]);
		int ans = Find(root, i + 1);
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}
