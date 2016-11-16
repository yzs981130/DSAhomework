#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string, int> sour;
map<int, string> original;
int p, q, r;
#define maxn 40
#define infi 1000000;
struct dist
{
	int len;
	int pre;
};
dist D[maxn][maxn];
void output(int s, int e)
{
	if (s == e)
	{
		cout << original[s];
		return;
	}
	output(s, D[s][e].pre);
	cout << "->" << '(' << D[D[s][e].pre][e].len << ')' << "->" << original[e];
}
int main()
{
	string tem;
	cin >> p;
	for (int i = 0; i < p; i++)
	{
		cin >> tem;
		sour.insert(pair<string, int>(tem, i));
		original.insert(pair<int, string>(i, tem));
	}

	for (int i = 0; i < p; i++)
		for (int j = 0; j < p; j++)
		{
			if (i != j)
			{
				D[i][j].len = infi;
				D[i][j].pre = -1;
			}
			else
			{
				D[i][j].len = 0;
				D[i][j].pre = i;
			}
		}
	cin >> q;
	string fol1, fol2;
	int len;

	for (int i = 0; i < q; i++)
	{
		cin >> fol1 >> fol2 >> len;
		if (D[sour[fol1]][sour[fol2]].len>len)
		{
			D[sour[fol1]][sour[fol2]].len = len;
			D[sour[fol1]][sour[fol2]].pre = sour[fol1];
			D[sour[fol2]][sour[fol1]].len = len;
			D[sour[fol2]][sour[fol1]].pre = sour[fol2];
		}
	}
	
	for (int g = 0; g < p; g++)
		for (int i = 0; i < p; i++)
			for (int j = 0; j < p; j++)
				if (D[i][j].len > D[i][g].len + D[g][j].len)
				{
					D[i][j].len = D[i][g].len + D[g][j].len;
					D[i][j].pre = D[g][j].pre;
				}
	cin >> r;
	while(r--)
	{
		cin >> fol1 >> fol2;
		output(sour[fol1], sour[fol2]);
		cout << endl;
	}
	system("pause");
	return 0;
}