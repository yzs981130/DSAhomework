#include <iostream>
using namespace std;
#define MAXN 100010

struct Node
{
	int L, R;
	long long add, value;
} tree[MAXN * 4];
long long arr[MAXN], sum = 0;

void Update(int);
void Build(int id, int l, int r)
{
	tree[id].L = l;
	tree[id].R = r;
	tree[id].add = 0;
	if (l == r)
	{
		tree[id].value = arr[l]; 
		return;
	}
	int mid = (l + r) >> 1;
	Build(id << 1, l, mid);
	Build((id << 1) + 1, mid + 1, r);
	tree[id].value = tree[id << 1].value + tree[(id << 1) + 1].value;
}
void Add(int id, int l, int r, long long v)
{
	if (l <= tree[id].L && tree[id].R <= r)
	{
		tree[id].add += v;
		tree[id].value += v*(tree[id].R - tree[id].L + 1);
		return;
	}
	Update(id);
	if (tree[id].L == tree[id].R) { return; }
	int mid = (tree[id].L + tree[id].R) >> 1;
	if (l > mid) 
		Add((id << 1) + 1, l, r, v);
	else if (r <= mid) 
		Add(id << 1, l, r, v);
	else
	{
		Add(id << 1, l, mid, v);
		Add((id << 1) + 1, mid + 1, r, v);
	}
	tree[id].value = tree[id << 1].value + tree[(id << 1) + 1].value;
}
void Update(int node)//小区间的值加上增量
{
	if (tree[node].add)
	{
		tree[node << 1].add += tree[node].add;
		tree[(node << 1) + 1].add += tree[node].add;
		tree[node << 1].value += (tree[node << 1].R - tree[node << 1].L + 1)*tree[node].add;
		tree[(node << 1) + 1].value += (tree[(node << 1) + 1].R - tree[(node << 1) + 1].L + 1)*tree[node].add;
		tree[node].add = 0;
	}
}//本节点区间的和实际上是value+add*(R-L+1)
void Solve(int id, int l, int r)//类似Add
{
	if (l <= tree[id].L && tree[id].R <= r)
	{
		sum += tree[id].value;
		return;
	}
	Update(id);

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
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q, l, r;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	Build(1, 1, n);
	char c;
	while(q--)
	{
		cin >> c;
		if(c == 'Q')
		{
			cin >> l >> r;
			sum = 0;
			Solve(1, l, r);
			cout << sum << endl;
		}
		else
		{
			long long v;
			cin >> l >> r >> v;
			Add(1, l, r, v);
		}
	}
	system("pause");
	return 0;
}