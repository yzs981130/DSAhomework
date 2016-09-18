#include <iostream> 
using namespace std;

struct monkey
{
	int num;
	monkey *next;
};

int joseph(int sum, int cycle)
{
	int i;
	monkey *p_old, *p_new, *head = NULL;

	head = new monkey;
	head->num = 1;
	p_old = head;
	for (i = 2; i <= sum; i++)
	{
		p_new = new monkey;
		p_new->num = i;
		p_old->next = p_new;
		p_old = p_new;
	}
	p_old->next = head;

	p_old = head;
	i = 1;
	while (1)
	{
		p_new = p_old->next;
		i++;
		if (p_new->num == p_old->num)
			break;
		if ((i % cycle) == 0)
		{
			p_old->next = p_new->next;
			p_old = p_old->next;
			delete p_new;
			i = 1;
		}
		else
			p_old = p_new;
	}

	return p_new->num;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << joseph(n, m) << endl;
	system("pause");
	return 0;
}