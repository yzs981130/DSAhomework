#include <iostream>
#include <cstdio>
using namespace std;

int n, m, _index, val;
int LowExt, offset;//最后一层外部节点数量、最后一层以上的节点数量
int ini[1000], b[2000];//b:内部节点，保存败者的下标，ini：初始的数组

int loser(int a, int b)//val大的是败者
{
	return ini[a]>ini[b] ? a : b;
}
int winner(int a, int b)
{
	return ini[a]>ini[b] ? b : a;
}
void play(int father, int left, int right)//竞赛
{
	int temp1 = 0, temp2 = 0;
	b[father] = loser(left, right);
	temp1 = winner(left, right);
	while (father>1 && father % 2 == 1)//沿着右子树向上比较
	{
		temp2 = winner(temp1, b[father / 2]);
		b[father / 2] = loser(temp1, b[father / 2]);//败者留在父节点
		temp1 = temp2;
		father /= 2;//再向上找父节点
	}
	b[father / 2] = temp1;//胜者放入b[0]或左孩子
}
void replay(int i)
{
	int father = 0;
	if (i <= LowExt)
		father = (i + offset) / 2;
	else
		father = (i - LowExt + n - 1) / 2;
	b[0] = winner(i, b[father]);//保存当前胜利节点
	b[father] = loser(i, b[father]);//父节点保存败者
	for (; (father / 2) >= 1; father /= 2)
	{
		int temp = 0;
		temp = winner(b[father / 2], b[0]);//将胜者和父节点比较
		b[father / 2] = loser(b[father / 2], b[0]);
		b[0] = temp;
	}
}
void make(int *a)//构造初始的败者树
{
	int i = 0, s = 0, size = n;
	for (s = 1; s * 2 <= n - 1; s += s);   //倒数第二层节点数
	LowExt = 2 * (size - s);
	//cout<<s<<endl;
	offset = 2 * s - 1;
	for (i = 2; i <= LowExt; i += 2)
	{
		play((offset + i) / 2, i - 1, i);//最底层外部节点比赛
	}
	if (size % 2)//外部节点数目是奇数，不能满足两两比较，要特殊处理
	{
		play(n / 2, b[(n - 1) / 2], LowExt + 1);//暂存在父节点中的左胜者和3号节点比赛
		i = LowExt + 3;
	}
	else
		i = LowExt + 2;
	for (; i <= n; i += 2)//处理完前面节点，再处理剩余节点
	{
		play((i - LowExt + n - 1) / 2, i - 1, i);//其他的外部节点的比较
	}

}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &ini[i]);

	make(b);

	for (int i = 0; i<n; i++)
		printf("%d ", ini[b[i]]);
	printf("\n");

	while (m--)
	{
		scanf("%d%d", &_index, &val);
		ini[_index + 1] = val;
		replay(_index + 1);
		for (int i = 0; i<n; i++)
			printf("%d ", ini[b[i]]);
		printf("\n");
	}

	return 0;
}