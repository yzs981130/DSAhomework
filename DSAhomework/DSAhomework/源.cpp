#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int que[80000];
int head = 0, rear = -1;
int main()
{
	int n, input;
	long long ans = 0;
	cin >> n;
	while (n--) 
	{
		cin >> input;
		while (rear >= head && input >= que[rear]) 
			rear--;
		que[++rear] = input;
		ans += rear - head;
	}
	cout << ans << endl;
	system("pause");
	return 0;
}