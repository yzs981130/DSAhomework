#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stack>
#define N 100
using namespace std;
void init(char s[])
{
	char *p = s;
	char temp[N], *p1 = temp;
	while (*p != '\0')
	{
		while (((*p == ' ') || (*p == '\t')) && (*p != '\0')) 
			*p++;
		*p1 = *p;
		p1++;
		p++;
	}
	*p1 = '\0';
	strcpy(s, temp);
}
int cal(char s[], int t, int n)
{
	if (n < t) return 0;
	if (n == t)
	{
		if (s[t] >= 'A' && s[t] <= 'Z') 
			return (s[t] - 'A');
		else if (s[t] >= 'a' && s[t] <= 'z') 
			return (s[t] - 'a');
		else 
			return s[t] - '0';
	}
	int f1 = -1, f2 = -1;
	int flag = 0;
	for (int i = t; i <= n; i++)
	{
		if (s[i] == '(') 
			flag++;
		else if (s[i] == ')') 
			flag--;
		else if ((s[i] == '+' || s[i] == '-') && flag == 0) 
			f1 = i;
		else if (s[i] == '*' && flag == 0) f2 = i;
	}
	if (f1 < 0 && f2 < 0) 
		return cal(s, t + 1, n - 1);
	if (f1 > 0)
	{
		if (s[f1] == '+') 
			return cal(s, t, f1 - 1) + cal(s, f1 + 1, n);
		else 
			return cal(s, t, f1 - 1) - cal(s, f1 + 1, n);
	}
	else 
		return cal(s, t, f2 - 1) * cal(s, f2 + 1, n);
}
int main() 
{
	int cnt;
	cin >> cnt;
	cin.ignore();
	while(cnt--)
	{
		char str1[N], str2[N];
		gets_s(str1);
		gets_s(str2);
		init(str1);
		init(str2);
		int a = cal(str1, 0, strlen(str1) - 1), b = cal(str2, 0, strlen(str2) - 1);
		cout << ((a == b) ? "YES" : "NO") << endl;
	}
	system("pause");
	return 0;
}