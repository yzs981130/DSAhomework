#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 160
string a;
string str[MAXN];
char tmp[MAXN];
int ans;

void Merge(int l, int m, int r)
{
	int i = l;
	int j = m + 1;
	int k = l;
	while (i <= m && j <= r)
	{
		if (a[i] > a[j])
		{
			tmp[k++] = a[j++];
			ans += m - i + 1;
		}
		else
			tmp[k++] = a[i++];
	}
	while (i <= m) 
		tmp[k++] = a[i++];
	while (j <= r) 
		tmp[k++] = a[j++];
	for (int i = l; i <= r; i++)
		a[i] = tmp[i];
}

void Merge_sort(int l, int r)
{
	if (l < r)
	{
		int m = (l + r) >> 1;
		Merge_sort(l, m);
		Merge_sort(m + 1, r);
		Merge(l, m, r);
	}
}
struct DNA
{
	int id;
	int value;
}p[MAXN];
int cmp(DNA a, DNA b)
{
	if (a.value == b.value)
		return a.id < b.id;
	return a.value < b.value;
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		cin >> str[i];
		p[i].id = i;
		memset(tmp, 0, sizeof(tmp));
		ans = 0;
		a = str[i];
		Merge_sort(0, n - 1);
		p[i].value = ans;
	}
	sort(p, p + m, cmp);
	for (int i = 0; i < m; i++)
		cout << str[p[i].id] << endl;
	system("pause");
	return 0;
}