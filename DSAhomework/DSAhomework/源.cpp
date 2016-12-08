#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
struct point
{
	double x, y;
}p[maxn];
struct node
{
	int u, v;
	double len;
}edge[maxn*maxn];
int pre[maxn], id[maxn], vis[maxn];
double in[maxn];
double dis(point a, point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double dir_mst(int root, int n, int m)
{
	double ans = 0;
	while (1)
	{
		for (int i = 0; i<n; ++i)
		{
			in[i] = inf;
		}
		for (int i = 0; i<m; ++i)
		{
			int u = edge[i].u, v = edge[i].v;
			if (edge[i].len<in[v] && u != v)
			{
				pre[v] = u; in[v] = edge[i].len;
			}
		}
		for (int i = 0; i<n; ++i)
		{
			if (i == root)
			{
				continue;
			}
			if (in[i] == inf)
			{
				return -1;	//如果某点入度为零，必定找不到 
			}
		}
		//检查这些边是否构成了环 
		memset(id, -1, sizeof(id));
		memset(vis, -1, sizeof(vis));
		in[root] = 0;
		int cnt = 0;
		for (int i = 0; i<n; ++i)//标记环 
		{
			ans += in[i];
			int v = i;
			while (vis[v] != i&&id[v] == -1 && v != root)
			{
				vis[v] = i;
				v = pre[v];
			}
			if (v != root&&id[v] == -1)//缩点 
			{
				for (int u = pre[v]; u != v; u = pre[u])
				{
					id[u] = cnt;
				}
				id[v] = cnt++;
			}
		}
		if (cnt == 0)
		{
			break;//无环 
		}
		for (int i = 0; i<n; ++i)
		{
			if (id[i] == -1)
			{
				id[i] = cnt++;
			}
		}
		//建立新图 
		for (int i = 0; i<m; ++i)
		{
			int u = edge[i].u, v = edge[i].v;
			edge[i].u = id[u];
			edge[i].v = id[v];
			if (id[u] != id[v])
			{
				edge[i].len -= in[v];
			}
		}
		n = cnt;
		root = id[root];
	}
	return ans;
}
int main()
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		for (int i = 0; i<n; ++i)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		for (int i = 0; i<m; ++i)
		{
			scanf("%d%d", &edge[i].u, &edge[i].v);
			--edge[i].u; --edge[i].v;
			if (edge[i].u != edge[i].v)
			{
				edge[i].len = dis(p[edge[i].u], p[edge[i].v]);
			}
			else
			{
				edge[i].len = inf;
			}
		}
		double ans = dir_mst(0, n, m);
		if (ans == -1)
		{
			printf("NO\n");
		}
		else
		{
			printf("%.2f\n", ans);
		}
	}
	return 0;
}