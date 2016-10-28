#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXSIZE 100000 
struct data
{
	int size;
	int heap[1000005];
	void swim(int x)
	{
		while (x>1)
		{
			if (heap[x] < heap[x >> 1])
				swap(heap[x], heap[x >> 1]);
			else break;
			x >>= 1;
		}
	}
	void sink(int x)
	{
		int mn = x;
		int l = (x << 1), r = ((x << 1) + 1);
		if (l <= size && heap[l] < heap[mn])
			mn = l;
		if (r <= size && heap[r] < heap[mn])
			mn = r;
		if (mn != x)
		{
			swap(heap[mn], heap[x]);
			sink(mn);
		}
	}
	void push(int a)
	{
		heap[++size] = a;
		swim(size);
	}
	void pop()
	{
		heap[1] = heap[size--];
		sink(1);
	}
	void clear()
	{
		size = 0;
		memset(heap, 0, sizeof(heap));
	}
}q;
int main()
{
	int n, T;
	scanf("%d", &T);
	while (T--)
	{
		q.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int opt, x;
			scanf("%d", &opt);
			if (opt == 1)
			{
				scanf("%d", &x);
				q.push(x);
			}
			else
			{
				printf("%d\n", q.heap[1]);
				q.pop();
			}
		}
	}
	system("pause");
	return 0;
}