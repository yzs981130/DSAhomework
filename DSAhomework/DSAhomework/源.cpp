#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define lowbit(x) (x&(-x))
using namespace std;
const int MAX = 100010;

struct Data
{
	int id, w;
}num[MAX];
int n, ar[MAX];

bool cmp(Data a, Data b)
{
	return a.w > b.w;
}

void add(int i)
{
	while (i <= n)
	{
		ar[i] += 1;
		i += lowbit(i);
	}
}

long long sum(int i)
{
	long long ans = 0;
	while (i)
	{
		ans += ar[i];
		i -= lowbit(i);
	}
	return ans;
}

int main()
{
	int i;
	scanf("%d", &n);
	memset(ar, 0, sizeof(ar));
	for (i = 0; i < n; i++)
	{
		num[i].id = i + 1;
		scanf("%d", &num[i].w);
	}
	sort(num, num + n, cmp);
	long long ans = 0;
	for (i = 0; i < n; i++)
	{
		ans += sum(num[i].id - 1);
		add(num[i].id);
	}
	printf("%lld\n", 1LL * n * (n - 1) / 2 - ans);
	return 0;
}