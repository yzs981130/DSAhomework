#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
using namespace std;
string str[55];
int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int s_len = s.length();
		int t_len = t.length();
		int cnt_s = 0;
		for (int i = 0; i < t_len; i++)
		{
			if (t[i] == s[cnt_s])
				cnt_s++;
		}
		if (cnt_s == s.length())
			printf("Yes\n");
		else
			printf("No\n");
	}
	system("pause");
	return 0;
}