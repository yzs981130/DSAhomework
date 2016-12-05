#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 1000000;
vector<int> c;
int a[MAX], b[MAX];
int main()
{
	int n, m;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);

	std::vector<int>::iterator it;
	c.resize(n + m);
	it = set_symmetric_difference(a, a + n, b, b + m, c.begin());
	c.resize(it - c.begin());

	for (int i = 0; i < c.size(); i++)
		printf("%d ", c[i]);
	return 0;
}