#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 12
#define eps 1e-6
struct Point
{
	int x, y, z;
}a[MAXN];
struct Distance
{
	int x, y, z;
	int p, q, r;
	int id, id2;
	float dis;
}d[MAXN * MAXN / 2];
int cmp(Distance a, Distance b)
{
	if (fabs(a.dis - b.dis) < eps)
	{
		if (a.id == b.id)
			return a.id2 < b.id2;
		else
			return (a.id < b.id);
	}
	return (a.dis > b.dis);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	int cnt = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			d[cnt].x = a[i].x;
			d[cnt].y = a[i].y;
			d[cnt].z = a[i].z;
			d[cnt].p = a[j].x;
			d[cnt].q = a[j].y;
			d[cnt].r = a[j].z;
			d[cnt].id = i;
			d[cnt].id2 = j;
			d[cnt].dis = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y) + (a[i].z - a[j].z) * (a[i].z - a[j].z));
			cnt++;
		}
	sort(d, d + cnt, cmp);
	for (int i = 0; i < cnt; i++)
		printf("(%d,%d,%d)-(%d,%d,%d)=%.2f\n", d[i].x, d[i].y, d[i].z, d[i].p, d[i].q, d[i].r, d[i].dis);
	system("pause");
	return 0;
}
