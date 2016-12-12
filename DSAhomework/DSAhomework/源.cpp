#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <stack>
#include <bitset>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 1000010
using namespace std;
queue<int>q;
int p[MAXN];
int main()
{
	int n, m, t;
	cin >> m >> n;
	memset(p, 0, sizeof(p));
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		bool exist = p[t];
		if (q.size() < m && !exist)
		{
			q.push(t);
			p[t]++;
		}
		else if (exist)
			ans++;
		else
		{
			int d = q.front();
			q.pop();
			p[d]--;
			q.push(t);
			p[t]++;
		}
	}
	cout << n - ans << endl;
	return 0;
}