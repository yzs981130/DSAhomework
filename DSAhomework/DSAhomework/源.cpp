#include<iostream>    
#include<string>
#include<cstdio>
using namespace std;
int c[200010];
int f[200010];
string a, b;
int n, m, k;

void getNext()
{
	for (int i = 1; i<m; ++i)
	{
		int j = f[i];
		while (j && b[i] != b[j])
			j = f[j];
		f[i + 1] = (b[i] == b[j]) ? j + 1 : 0;
	}
}

void find()
{
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		while (j && a[i] != b[j])
			j = f[j];
		if (a[i] == b[j])
			j++;
		c[j]++;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	cin >> a >> b;
	getNext();
	find();
	for (int i = m; i > 0; --i)
		c[f[i]] += c[i];
	for (int i = 0; i <= m; ++i)
		c[i] -= c[i + 1];
	for (int i = 1; i <= k; ++i)
	{
		int r;
		cin >> r;
		cout << c[r] << endl;
	}
	return 0;
}