#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define MAXN 1000010
char str[MAXN];
int Next[MAXN];
void makeNext(int len)
{
	int i = 0, j = -1;
	Next[0] = -1;
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
	int n, t = 1;
	while (scanf("%d", &n) && n != 0)
	{
		getchar();
		scanf("%s", &str);
		memset(Next, 0, sizeof(Next));
		printf("Test case #%d\n", t++);
		int len = strlen(str);
		makeNext(len);
		for (int i = 2; i <= len; i++)
			if (i % (i - Next[i]) == 0 && Next[i] > 0)
				printf("%d %d\n", i, i / (i - Next[i]));
		printf("\n");
	}
	system("pause");
	return 0;
}