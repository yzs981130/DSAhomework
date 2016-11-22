#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;
int p[1000010];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	k--;
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	nth_element(p, p + k, p + n);
	printf("%d\n", p[k]);
	return 0;
}