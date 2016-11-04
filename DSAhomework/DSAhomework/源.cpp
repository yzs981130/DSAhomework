#define _CRT_SECURE_NO_WARNINGS
#include<queue>
#include<cstdio>
#include <iostream>
#include <functional>
using namespace std;
int n, tmp, ans;
priority_queue<int, vector<int>, greater<int> >q;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		q.push(tmp);
	}
	while (q.size() != 1)
	{
		int a, b;
		a = q.top(); q.pop();
		b = q.top(); q.pop();
		ans += (a + b);
		q.push(a + b);
	}
	cout << ans;
	system("pause");
	return 0;
}