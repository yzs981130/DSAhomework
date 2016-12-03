#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
using namespace std;
#define MAXN 100010
int a[MAXN];
int que[MAXN];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int i = 0, head = 0, rear = -1;
	while (i < n)
	{
		while (a[i] <= a[que[rear]] && rear >= head)
			rear--;
		que[++rear] = i;
		while (rear >= head && que[head] < i - k + 1)
			head++;
		if (i >= k - 1)
			printf("%d ", a[que[head]]);
		i++;
	}
	printf("\n");
	i = 0;
	head = 0;
	rear = -1;
	while (i < n)
	{
		while (a[i] >= a[que[rear]] && rear >= head)
			rear--;
		que[++rear] = i;
		while (rear >= head && que[head] < i - k + 1)
			head++;
		if (i >= k - 1)
			printf("%d ", a[que[head]]);
		i++;
	}
	system("pause");
	return 0;
}