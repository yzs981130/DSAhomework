#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct item
{
	int k;
	item *next;
};

void Add(item *head, int k)
{
	while (head != NULL)
	{
		head->k += k;
		head->k %= 65536;
		head = head->next;
	}
}
int Query(item *head, int k)
{
	int cnt = 0;
	while (head != NULL)
	{
		if (head->k & (1 << k))
			cnt++;
		head = head->next;
	}
	return cnt;
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	item *head = NULL, *current = NULL, *tail = NULL;
	head = current;
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		current = new item;
		current->k = t;
		current->next = NULL;
		if (head == NULL)
		{
			head = current;
			tail = head;
		}
		else
		{
			tail->next = current;
			tail = current;
		}
	}
	for (int i = 0; i < m; i++)
	{
		char c;
		cin >> c;
		if (c == 'C')
		{
			int t;
			scanf("%d", &t);
			Add(head, t);
		}
		else if (c == 'Q')
		{
			int t;
			scanf("%d", &t);
			printf("%d\n", Query(head, t));
			getchar();
		}
	}
	while (head != NULL)
	{
		item *temp = head->next;
		delete head;
		head = temp;
	}
	system("pause");
	return 0;
}