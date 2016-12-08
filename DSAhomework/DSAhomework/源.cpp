#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;
#define MAXN 50
#define INFI 99999
map<string, int>m1;
map<int, string>m2;
struct dist
{
	int len;
	int pre;
}D[MAXN][MAXN];
void output(int s, int e)
{
	if (s == e)
	{
		cout << m2[s];
		return;
	}
	output(s, D[s][e].pre);
	cout << "->(" << D[D[s][e].pre][e].len << ")->" << m2[e];
}
int main()
{
	int p, q, r, dis;
	scanf("%d", &p);
	string a, b;
	for (int i = 0; i < p; i++)
	{
		cin >> a;
		m1[a] = i;
		m2[i] = a;
	}
	for (int i = 0; i < p; i++)
		for (int j = 0; j < p; j++)
		{
			if (i != j)
			{
				D[i][j].len = INFI;
				D[i][j].pre = -1;
			}
			else
			{
				D[i][j].len = 0;
				D[i][j].pre = i;
			}
		}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) 
	{
		cin >> a >> b >> dis;
		if (D[m1[a]][m1[b]].len > dis)
		{
			D[m1[a]][m1[b]].len = dis;
			D[m1[a]][m1[b]].pre = m1[a];
			D[m1[b]][m1[a]].len = dis;
			D[m1[b]][m1[a]].pre = m1[b];
		}
	}
	for(int k = 0; k < p; k++)
		for(int i = 0; i < p; i++)
			for (int j = 0; j < p; j++)
				if (D[i][j].len > D[i][k].len + D[k][j].len)
				{
					D[i][j].len = D[i][k].len + D[k][j].len;
					D[i][j].pre = D[k][j].pre;
				}
	
	scanf("%d", &r);
	for (int i = 0; i < r; i++)
	{
		cin >> a >> b;
		output(m1[a], m1[b]);
		cout << endl;
	}
	system("pause");
	return 0;
}