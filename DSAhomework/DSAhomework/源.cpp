#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;
#define maxn 201000
int len1, len2;
char s[maxn];
int sa[maxn], Rank[maxn], height[maxn];
int t1[maxn], t2[maxn], c[maxn], n;
void build_sa(int m)
{
	int i, *x = t1, *y = t2;
	for (i = 0; i<m; i++) c[i] = 0;
	for (i = 0; i<n; i++) c[x[i] = s[i]]++;
	for (i = 1; i<m; i++) c[i] += c[i - 1];
	for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
	for (int k = 1; k <= n; k <<= 1)
	{
		int p = 0;
		for (i = n - k; i<n; i++) y[p++] = i;
		for (i = 0; i<n; i++)if (sa[i] >= k) y[p++] = sa[i] - k;
		for (i = 0; i<m; i++) c[i] = 0;
		for (i = 0; i<n; i++) c[x[y[i]]]++;
		for (i = 1; i<m; i++) c[i] += c[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
		swap(x, y);
		p = 1; x[sa[0]] = 0;
		for (i = 1; i<n; i++)
			x[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? p - 1 : p++;
		if (p >= n) break;
		m = p;
	}
}
void build_height()
{
	int i, j, k = 0;
	for (i = 0; i<n; i++) Rank[sa[i]] = i;
	for (i = 0; i<n; i++)
	{
		if (k)k--;
		j = sa[Rank[i] - 1];
		while (s[i + k] == s[j + k]) k++;
		height[Rank[i]] = k;
	}
}
int solve()
{
	int ans = 0;
	for (int i = 2; i<n; i++)
	{
		int a1 = sa[i - 1], a2 = sa[i];
		if (a1>a2) swap(a1, a2);
		if (a1 >= 0 && a1 <= len1 - 1 && a2 >= len1 + 1 && a2 <= len1 + len2)
			ans = max(ans, height[i]);
	}
	return ans;
}
int main()
{
	scanf("%s", s);
	len1 = strlen(s);
	s[len1] = 1;
	scanf("%s", s + len1 + 1);
	len2 = strlen(s) - len1 - 1;
	n = len1 + len2 + 2;
	s[len1 + len2 + 1] = 0;
	build_sa(128);
	build_height();
	printf("%d\n", solve());
	system("pause");
	return 0;
}