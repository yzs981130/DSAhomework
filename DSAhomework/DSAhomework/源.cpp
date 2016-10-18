#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define lowbit(x) (x&(-x))
using namespace std;
const int NMAX = 15005;
const int MMAX = 32005;
int n, arr[MMAX], cnt[NMAX];
void add(int i) 
{
	while (i <= MMAX) 
	{
		arr[i] += 1;
		i += lowbit(i);
	}
}

int sum(int i) 
{
	int ans = 0;
	while (i) 
	{
		ans += arr[i];
		i -= lowbit(i);
	}
	return ans;
}

int main() 
{
	int i, x, y;
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
	{
		scanf("%d %d", &x, &y);
		cnt[sum(x + 1)]++;
		add(x + 1);
	}
	for (i = 0; i < n; i++)
		printf("%d\n", cnt[i]);
	system("pause");
	return 0;
}