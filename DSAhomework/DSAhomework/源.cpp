#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 50010
int ansmax, ansmin;
struct Node
{
	int L, R;
	int _max, _min;
} tree[MAXN * 4];
int arr[MAXN], sum = 0;

void Build(int id, int l, int r)
{
	tree[id].L = l;
	tree[id].R = r;
	if (l == r)
	{
		tree[id]._max = arr[l];
		tree[id]._min = arr[l];
		return;
	}
	int mid = (l + r) >> 1;
	Build(id << 1, l, mid);
	Build((id << 1) + 1, mid + 1, r);
	tree[id]._max = max(tree[id << 1]._max, tree[(id << 1) + 1]._max);
	tree[id]._min = min(tree[id << 1]._min, tree[(id << 1) + 1]._min);
}
void Solve(int id, int l, int r)
{
	if (l == tree[id].L && tree[id].R == r)
	{
		ansmax = max(ansmax, tree[id]._max);
		ansmin = min(ansmin, tree[id]._min);
		return;
	}

	if (tree[id].L == tree[id].R) 
		return;
	int mid = (tree[id].L + tree[id].R) >> 1;
	if (l > mid) 
		Solve((id << 1) + 1, l, r);
	else if (r <= mid) 
		Solve(id << 1, l, r);
	else
	{
		Solve(id << 1, l, mid);
		Solve((id << 1) + 1, mid + 1, r);
	}

}

int main() 
{
	int n, q, l, r;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", arr + i);
	Build(1, 1, n);
	while(q--)
	{
		ansmax = 0;
		ansmin = INT_MAX;
		scanf("%d %d", &l, &r);
		if(l == r)
		{
			printf("0\n");
			continue;
		}
		Solve(1, l, r);
		printf("%d\n", ansmax - ansmin);
	}
	system("pause");
	return 0;
}