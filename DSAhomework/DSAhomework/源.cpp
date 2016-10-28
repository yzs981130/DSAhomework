#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
#define MAXN 1000010
char s[MAXN];
int Next[MAXN];
int main()
{
	int len, t = 1;
	string str;
	while(scanf("%d", &len) && len != 0)
	{
		memset(s, 0, sizeof(s));
		memset(Next, 0, sizeof(Next));
		scanf("%s", s);
		Next[0] = -1;
		int j = 0, k = -1;
		while(j < len)
		{
			if (k == -1 || s[j] == s[k])
			{
				++j;
				++k;
				Next[j] = k;
			}
			else
				k = Next[k];
		}
		printf("Test case #%d\n", t);
		++t;
		for (int i = 2; i <= len; ++i)
		{
			j = i - Next[i];
			if (i % j == 0 && i > j)
				printf("%d %d\n", i, i / j);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}