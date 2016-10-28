#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
#define MAXSIZE 100000
struct Node
{
	char c;
	bool flag;
	int depth;
	Node *L;
	Node *R;
};
Node* BuildTree()
{
	string s;
	int len, top = 1;
	stack<Node*> Stack;
	cin >> s;
	Node *root = new Node;
	root->c = s[0];
	root->L = nullptr;
	root->R = nullptr;
	root->depth = 0;
	root->flag = false;
	Stack.push(root);
	while (cin >> s && s != "0")
	{
		len = s.length();
		Node *new_Node = new Node;
		new_Node->c = s[len - 1];
		new_Node->L = nullptr;
		new_Node->R = nullptr;
		new_Node->depth = len - 1;
		new_Node->flag = false;

		Node *r = Stack.top();
		while (new_Node->depth - r->depth != 1)
		{
			Stack.pop();
			r = Stack.top();
		}
		if (new_Node->c == '*')
		{
			r->flag = true;
			continue;
		}

		if (!r->flag)
		{
			r->L = new_Node;
			r->flag = true;
		}
		else if (r->flag)
			r->R = new_Node;

		Stack.push(new_Node);
	}
	return root;
}
void PreOrder(Node *root)
{
	if (root)
	{
		cout << root->c;
		PreOrder(root->L);
		PreOrder(root->R);
	}
}
void InOrder(Node *root)
{
	if (root)
	{
		InOrder(root->L);
		cout << root->c;
		InOrder(root->R);
	}
}
void PostOrder(Node *root)
{
	if (root)
	{
		PostOrder(root->L);
		PostOrder(root->R);
		cout << root->c;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		Node *root = BuildTree();
		PreOrder(root);
		cout << endl;
		PostOrder(root);
		cout << endl;
		InOrder(root);
		cout << endl;
		cout << endl;
	}
	system("pause");
	return 0;
}