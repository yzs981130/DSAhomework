#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100010
#define MAXM 50010
struct Node
{
	Node *ch[2];
	int r, v;
	int s;
	Node(int _v)
	{
		v = _v;
		r = rand();
		s = 1;
		ch[0] = ch[1] = NULL;
	}
	void Resize()
	{
		s = 1;
		if (ch[0]) 
			s += ch[0]->s;
		if (ch[1]) 
			s += ch[1]->s;
	}
};
void Rotate(Node* &p, int d)
{
	Node *k = p->ch[d ^ 1];
	p->ch[d ^ 1] = k->ch[d];
	k->ch[d] = p;
	p->Resize();
	k->Resize();
	p = k;
}
void Insert(Node* &p, int v)
{
	if (!p) 
		p = new Node(v);
	else
	{
		int d = v < p->v ? 0 : 1;
		Insert(p->ch[d], v);
		if (p->ch[d]->r > p->r)
			Rotate(p, d ^ 1);
	}
	p->Resize();
}
void Remove(Node* &p, int v)
{
	if (p->v == v)
	{
		Node *u = p;
		if (p->ch[0] && p->ch[1])
		{
			int flag = p->ch[0]->r < p->ch[1]->r ? 0 : 1;
			Rotate(p, flag);
			Remove(p->ch[flag], v);
		}
		else
		{
			if (!p->ch[0]) 
				p = p->ch[1];
			else 
				p = p->ch[0];
			delete u;
		}
	}
	else 
		Remove(p->ch[(p->v < v)], v);
	if (p) 
		p->Resize();
}
int Find(Node *p, int k)
{
	int s = (p->ch[0]) ? p->ch[0]->s : 0;
	if (k == s + 1) 
		return p->v;
	else if (k <= s) 
		return Find(p->ch[0], k);
	else 
		return Find(p->ch[1], k - s - 1);
}

struct query
{
	int l, r, k;
	int id;
	bool operator < (const query&b) const
	{
		return l < b.l;
	}
}qs[MAXM];
int n, m;
int val[MAXN];
int ans[MAXM];
int main()
{
	Node *root = NULL;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &val[i]);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &qs[i].l, &qs[i].r, &qs[i].k);
		qs[i].id = i;
	}
	sort(qs + 1, qs + m + 1);
	int L = 1, R = 1;
	for (int i = 1; i <= m; i++)
	{
		while (L < qs[i].l)
		{
			if (L < R)
				Remove(root, val[L]);
			L++;
		}
		if (R < L)
			R = L;
		while (R <= qs[i].r)
		{
			Insert(root, val[R]);
			R++;
		}
		ans[qs[i].id] = Find(root, qs[i].k);
	}
	for (int i = 1; i <= m; i++) 
		printf("%d\n", ans[i]);
	system("pause");
	return 0;
}
