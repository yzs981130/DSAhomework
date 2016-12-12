#include <iostream>
#include <stdio.h>
using namespace std;

int _case, bug, flag, action, a, b;
int father[2100], r[2100];

int root(int x)
{
	int temp;
	if (x == father[x])
		return father[x];
	temp = root(father[x]);
	r[x] = (r[x] + r[father[x]]) % 2;
	father[x] = temp;

	return father[x];
}

void Union(int x, int y)
{
	int fx = root(x);
	int fy = root(y);

	if (fx != fy)
	{
		father[fx] = fy;

		if (r[y] == 0)
			r[fx] = 1 - r[x];
		else
			r[fx] = r[x];
	}
	else
	{
		if (r[x] == r[y])
			flag = 1;
	}
}

int main()
{
	scanf("%d", &_case);
	for (int t = 1; t <= _case; t++)
	{
		flag = 0;
		printf("Scenario #%d:\n", t);
		scanf("%d%d", &bug, &action);
		for (int i = 1; i <= bug; i++)
		{
			father[i] = i;
			r[i] = 0;
		}

		while (action--)
		{
			scanf("%d%d", &a, &b);
			if (flag == 0)
				Union(a, b);
		}

		if (flag == 1)
			printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");
		printf("\n");
	}
	return 0;
}