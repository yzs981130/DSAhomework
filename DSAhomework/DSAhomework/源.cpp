#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct item
{
	int k;
	int ex;
	item *next;
};
bool Equal = false;
item *search(item *head, int exp, int k)
{
	while (head->next)
	{
		if (head->next->ex == exp)
		{
			head->next->k += k;
			Equal = true;
		}
		if (head->next->ex < exp)
			break;
		head = head->next;
	}
	return head;
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		item *head = NULL, *current = NULL;
		int k, exp;
		for (int i = 0; i < 2; i++)
		{
			while (scanf("%d %d", &k, &exp) && exp >= 0)
			{
				current = new item;
				current->k = k;
				current->ex = exp;
				current->next = NULL;
				if (head == NULL)
					head = current;
				else if (exp > head->ex)
				{
					current->next = head;
					head = current;
				}
				else if (exp == head->ex)
				{
					head->k += k;
					delete current;
				}
				else
				{
					item *temp = search(head, current->ex, current->k);
					if (!Equal)
					{
						current->next = temp->next;
						temp->next = current;
					}
					Equal = false;
				}
			}
		}
		current = head;
		while (current->next)
		{
			if (current->k != 0)
				printf("[ %d %d ] ", current->k, current->ex);
			current = current->next;
		}
		if (current->k != 0)
			printf("[ %d %d ] ", current->k, current->ex);
		printf("\n");
		while (head != NULL)
		{
			item *temp = head->next;
			delete head;
			head = temp;
		}
	}
	system("pause");
	return 0;
}