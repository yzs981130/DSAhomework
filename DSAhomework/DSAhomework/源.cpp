#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 3000
struct Peanut
{
	int x, y;
	int value;
}peanuts[MAXN];
int cmp(Peanut p, Peanut q)
{
	if (p.value > q.value)
		return 1;
	return 0;
}
struct Ans
{
	int id;
	int benefit;
	int cost;
}ans[MAXN];
int dis(const Peanut &a, const Peanut &b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}
int cmp2(Ans a, Ans b)
{
	if (a.cost < b.cost || ((a.cost == b.cost) && (a.benefit < b.benefit)))
		return 1;
	return 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int m, n, k;
		scanf("%d %d %d", &m, &n, &k);
		int cnt = 0;
		for(int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				peanuts[cnt].x = i;
				peanuts[cnt].y = j;
				scanf("%d", &peanuts[cnt++].value);
			}
		sort(peanuts, peanuts + m * n, cmp);
		
		ans[0].benefit = peanuts[0].value;
		ans[0].id = 1;
		ans[0].cost = 2 * (peanuts[0].x + 1);

		for (int i = 1; i < m * n; i++)
		{
			if (peanuts[i].value == 0)
			{
				cnt = i;
				break;
			}
			ans[i].benefit = ans[i - 1].benefit + peanuts[i].value;
			ans[i].cost = ans[i - 1].cost - peanuts[i - 1].x + peanuts[i].x + dis(peanuts[i], peanuts[i - 1]);
			ans[i].id = ans[i - 1].id + 1;
		}
		sort(ans, ans + cnt, cmp2);
		int t = 0, tmp_cost = 0, tmp_benefit = 0;
		for (int i = 0; i < cnt; i++)
		{
			if (ans[i].cost + ans[i].id <= k)
				tmp_benefit = ans[i].benefit;
			else break;
		}
		printf("%d\n", tmp_benefit);
	}
	system("pause");
	return 0;
}