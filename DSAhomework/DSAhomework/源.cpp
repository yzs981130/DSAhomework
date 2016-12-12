#define _CRT_SECURE_NO_WARNINGS
#include<iostream>    
#include<string>
#include<cstdio>
using namespace std;
#define MAXN 10010
struct Node
{
	int benefit;
	int time;
	bool valid;
}nodes[MAXN];
int main()
{
	int n, maxt = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &nodes[i].benefit, &nodes[i].time);
		nodes[i].valid = true;
		if (nodes[i].time > maxt)
			maxt = nodes[i].time;
	}
	for (int i = maxt; i > 0; i--)
	{
		int maxV = 0, maxI = 0;
		bool flag = false;
		for(int j = 0; j < n; j++)
			if (nodes[j].time >= i && nodes[j].valid && nodes[j].benefit > maxV)
			{
				maxV = nodes[j].benefit;
				maxI = j;
				flag = true;
			}
		if (flag)
		{
			ans += nodes[maxI].benefit;
			nodes[maxI].valid = 0;
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}