#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
#define MAXN 1000010
struct Node
{
	char c;
	Node *l, *r;
	int d;
	int depth;
};
Node *build()
{
	string s;
	stack<Node*>Stack;
	cin >> s;
	Node *root = new Node;
	root->c = s[0];
	root->l = NULL;
	root->r = NULL;
	root->depth = 0;
	root->d = 0;
	Stack.push(root);
	while (cin >> s && s != "0")
	{
		int len = s.length();
		Node *current = new Node;
		current->c = s[len - 1];
		current->depth = len - 1;
		current->l = NULL;
		current->r = NULL;
		current->d = 0;
		Node *r = Stack.top();
		while (current->depth - r->depth != 1)
		{
			Stack.pop();
			r = Stack.top();
		}
		if (current->c == '*')
		{
			r->d++;
			continue;
		}
		if (r->d == 0)
		{
			r->l = current;
			r->d++;
		}
		else if (r->d == 1)
		{
			r->r = current;
			r->d++;
		}
		Stack.push(current);
	}
	return root;
}
void pre(Node *root)
{
	if (root)
	{
		cout << root->c;
		pre(root->l);
		pre(root->r);
	}
}
void in(Node *root)
{
	if (root)
	{
		in(root->l);
		cout << root->c;
		in(root->r);
	}
}
void post(Node *root)
{
	if (root)
	{
		post(root->l);
		post(root->r);
		cout << root->c;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		Node *root = build();
		pre(root);
		cout << endl;
		post(root);
		cout << endl;
		in(root);
		cout << endl;
		cout << endl;
	}
	system("pause");
	return 0;
}