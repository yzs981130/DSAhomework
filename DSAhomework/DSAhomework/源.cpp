#include <iostream>
using namespace std;
int p[150010];
int find(int x)
{
	if (p[x] == x)
		return x;
	p[x] = find(p[x]);
	return p[x];
}
void unite(int x, int y)
{
	int u, v;
	u = find(x);
	v = find(y);
	if (u != v) 
		p[u] = v;
}
int main()
{
	int i, n, k, d, x, y, ans = 0;
	cin >> n >> k;
	for (i = 1; i <= 3 * n; i++) 
		p[i] = i;
	while (k--)
	{
		cin >> d >> x >> y;
		if (x > n || y > n) 
			ans++;
		else if (d == 1)
		{
			if (find(x) == find(y + n) || find(x) == find(y + 2 * n)) 
				ans++;
			else
			{
				unite(x, y);
				unite(x + n, y + n);
				unite(x + 2 * n, y + 2 * n);
			}
		}
		else if(d == 2)
		{
			if (find(x) == find(y) || find(x) == find(y + 2 * n)) 
				ans++;
			else
			{
				unite(x, y + n);
				unite(x + n, y + 2 * n);
				unite(x + 2 * n, y);
			}
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}