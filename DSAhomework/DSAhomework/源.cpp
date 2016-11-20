#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <string>
#include <queue>
#define MAXN 30010
using namespace std;
priority_queue<int, vector<int>, greater<int> >small;
priority_queue<int, vector<int>, less<int> >big;

int main()
{
	int cnt = 0;
	int m, n, num[MAXN], t;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> num[i];
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		while(cnt < t)
			small.push(num[cnt++]);
		while (!big.empty() && big.top() > small.top())
		{
			int bt = big.top();
			int st = small.top();
			big.pop();
			small.pop();
			big.push(st);
			small.push(bt);
		}
		cout << small.top() << endl;
		big.push(small.top());
		small.pop();
	}
	system("pause");
	return 0;
}