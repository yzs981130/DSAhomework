#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
using namespace std;
stack<char>s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	int len = str.length();
	bool ans = true;
	for (int i = 0; i < len && ans; i++)
	{
		char c = str[i];
		if (c == '(' || c == '[' || c == '{')
			s.push(c);
		else if (c == ')')
		{
			if (s.empty())
			{
				ans = false;
				break;
			}
			char t = s.top();
			if (t == '(')
				s.pop();
		}
		else if (c == ']')
		{
			if (s.empty())
			{
				ans = false;
				break;
			}
			char t = s.top();
			if (t == '[')
				s.pop();
		}
		else if (c == '}')
		{
			if (s.empty())
			{
				ans = false;
				break;
			}
			char t = s.top();
			if (t == '{')
				s.pop();
		}
	}
	if (s.empty() && ans)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}