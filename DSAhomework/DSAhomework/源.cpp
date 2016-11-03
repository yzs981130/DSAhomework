#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lowbit(x) (x&(-x))
using namespace std;
const int MAX = 100005;

struct Data 
{
	int id, s, e;
}pre, cow[MAX];
int n, maxVal, ar[MAX];

bool cmp(Data a, Data b) 
{
	if (a.e == b.e) 
		return a.s < b.s;
	return a.e > b.e;
}

void add(int i) 
{
	while (i <= maxVal) 
	{
		ar[i] += 1;
		i += lowbit(i);
	}
}

int sum(int i) 
{
	int ans = 0;
	while (i > 0) 
	{
		ans += ar[i];
		i -= lowbit(i);
	}
	return ans;
}

int main() 
{
	int i, s, e, ans[MAX];
	while (scanf("%d", &n) && n) 
	{
		memset(ar, 0, sizeof(ar));
		maxVal = 0;
		for (i = 0; i < n; i++) 
		{
			scanf("%d%d", &s, &e);
			s++;
			e++;
			cow[i].s = s;
			cow[i].e = e;
			cow[i].id = i;
			if (maxVal < cow[i].s)
				maxVal = cow[i].s;
		}
		sort(cow, cow + n, cmp);
		int cnt = 0;
		pre.e = pre.s = -1;
		for (i = 0; i < n; i++) 
		{
			if (cow[i].s == pre.s && cow[i].e == pre.e) 
				cnt++;//牛相同直接赋值
			else 
			{
				cnt = 0;
				pre.s = cow[i].s;
				pre.e = cow[i].e;
			}
			ans[cow[i].id] = sum(cow[i].s) - cnt;
			add(cow[i].s);
		}
		for (i = 0; i < n - 1; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[i]);
	}
	return 0;
}