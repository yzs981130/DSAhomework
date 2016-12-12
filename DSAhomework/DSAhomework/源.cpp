#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n, m;
struct node {
	int y, di, fee;
	node(int yy, int dii, int fe)
	{
		y = yy, di = dii, fee = fe;
	}node() {}
	bool operator < (const struct node a)const
	{
		if (a.di == di) return a.fee<fee;
		return a.di<di;
	}
}now, nex;
int maxx;
int dis[110];
vector<node> lin[110];
priority_queue<node> q;
int dj()
{
	q.push(node(1, 0, 0));
	while (!q.empty())
	{
		now = q.top();

		q.pop();
		if (now.y == n) return now.di;
		for (int i = 0; i<lin[now.y].size(); i++)
		{

			if (now.fee + lin[now.y][i].fee <= maxx)
				q.push(node(lin[now.y][i].y, now.di + lin[now.y][i].di, now.fee + lin[now.y][i].fee));
		}
	}
	return -1;
}

int main()
{
	scanf("%d%d%d", &maxx, &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int aa, bb, cc, dd;
		scanf("%d%d%d%d", &aa, &bb, &cc, &dd);
		lin[aa].push_back(node(bb, cc, dd));
	}
	printf("%d\n", dj());
	return 0;
}