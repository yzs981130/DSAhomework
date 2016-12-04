#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define MAXN 1000010
char str[MAXN];
int Next[MAXN];
void findNext(int len)
{
	Next[0] = -1;
	int i = 0, j = -1;
	while (i < len)
	{
		if (j == -1 || str[i] == str[j])
		{
			i++;
			j++;
			Next[i] = j;
		}
		else
			j = Next[j];
	}
}
int main()
{
	while (scanf("%s", &str) && str[0] != '.')
	{
		memset(Next, 0, sizeof(Next));
		int i = strlen(str);
		findNext(i);
		if (i % (i - Next[i]) || Next[i] == 0)
			printf("1\n");
		else
			printf("%d\n", i / (i - Next[i]));
	}
	system("pause");
	return 0;
}