#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 50010
int a[MAXN];
int b[MAXN];
struct Cow
{
	int a, b;
	int id;
}cow[MAXN];
int cmp(Cow p, Cow q)
{
	if (p.a > q.a)
		return 1;
	else
		return 0;
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &cow[i].a, &cow[i].b);
		cow[i].id = i;
	}
	sort(cow, cow + n, cmp);
	int ans = 0, max_b = 0;
	for(int i = 0; i < k; i++)
		if (cow[i].b > max_b)
		{
			max_b = cow[i].b;
			ans = cow[i].id;
		}
	printf("%d\n", ans + 1);
	system("pause");
	return 0;
}