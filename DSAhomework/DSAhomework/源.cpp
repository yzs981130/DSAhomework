#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;
#define OFFSET 1000000
#define MAXN 2000100
int a[MAXN];
int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	int m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		m += OFFSET;
		a[m] += 1;
	}
	int cnt = 0;
	for (int i = 0; i < MAXN; i++)
	{
		if (!a[i])continue;
		if (i + t < 0 || i + t > MAXN)continue;
		if (!a[i + t])continue;
		a[i]--;
		if (!a[i + t])
		{
			a[i]++;
			continue;
		}
		a[i + t]--;
		cnt++;
		a[i]++;
		a[i + t]++;
	}
	printf("%d\n", cnt);
	system("pause");
	return 0;
}