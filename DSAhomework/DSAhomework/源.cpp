#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
struct node
{
	int x, y, step;
	bool operator<(const node &t)const
	{
		return step >t.step;
	}
};
int n, m;
int mmap[1000][1000], vis[1000][1000];
int dx[] = {-1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1};
void bfs(int s, int e)
{
	memset(vis, 0, sizeof(vis));
	priority_queue<node>Q;
	node next, tail;
	tail.x = s;
	tail.y = e;
	tail.step = 0;
	Q.push(tail);
	vis[s][e] = 1;
	while (!Q.empty())
	{
		tail = Q.top();
		Q.pop();
		if (tail.x == 1 && tail.y == 1)
		{
			cout << tail.step << endl;
			return;
		}
		for (int i = 0; i<4; i++)
		{
			next.x = tail.x + dx[i];
			next.y = tail.y + dy[i];
			if (mmap[next.x][next.y] != 1 && !vis[next.x][next.y])
			{
				if (mmap[next.x][next.y] == 2)
					next.step = tail.step + 1;
				else next.step = tail.step;
				Q.push(next);
				vis[next.x][next.y] = 1;
			}
		}
	}
	cout << "-1" << endl;
}
int main()
{
	int x, y, d, t;
	double s, e;

	while (cin >> n >> m)
	{
		memset(mmap, 0, sizeof(mmap));
		if (n == -1 && m == -1)
			break;
		for (int i = 1; i <= n; i++)
		{
			cin >> x >> y >> d >> t;
			if (d)
			{
				for (int j = y * 2; j <= (y + t) * 2; j++)
					mmap[j][x * 2] = 1;
			}
			else
			{
				for (int j = x * 2; j <= (x + t) * 2; j++)
					mmap[y * 2][j] = 1;
			}

		}
		for (int i = 1; i <= m; i++)
		{
			cin >> x >> y >> d;
			if (d)
				mmap[y * 2 + 1][x * 2] = 2;
			else
				mmap[y * 2][x * 2 + 1] = 2;
		}
		cin >> s >> e;
		int ss = (int)s * 2 + 1;
		int ee = (int)e * 2 + 1;
		if (!n && !m)
			cout << "0" << endl;
		else if (s < 0 || s > 199 || ee < 0 || ee > 199)
			cout << "0" << endl;
		else
		{
			for (int i = 0; i <= 400; i++)
				mmap[i][0] = mmap[i][400] = mmap[0][i] = mmap[400][i] = 1;
			bfs(ee, ss);
		}
	}
	return 0;
}