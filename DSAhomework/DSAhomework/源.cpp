#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#define MAXN 100010
int innerOrder[MAXN], backOrder[MAXN], d[MAXN];;
struct BNode
{
	int value;
	BNode *Left;
	BNode *Right;
};
BNode *build(int _innerStart, int _innerEnd, int _backStart, int _backEnd)
{
	BNode *root = new BNode;
	root->value = backOrder[_backEnd];
	int n = 0;
	while (innerOrder[_innerStart + n] != root->value && n < MAXN)
		n++;
	if (n)
		root->Left = build(_innerStart, _innerStart + n - 1, _backStart, _backStart + n - 1);
	else
		root->Left = nullptr;
	if (_innerStart + n < _innerEnd)
		root->Right = build(_innerStart + n + 1, _innerEnd, _backStart + n, _backEnd - 1);
	else
		root->Right = nullptr;
	return root;
}
void Travel(BNode *root)
{
	if (root)
	{
		cout << root->value << ' ';
		Travel(root->Left);
		Travel(root->Right);
	}
}
int main()
{
	int i = 0;
	while (cin >> innerOrder[i++])
	{
		if (cin.get() != ' ')   //遇到回车则停止输入  
			break;
	}
	i = 0;
	while (cin >> backOrder[i++])
	{
		if (cin.get() != ' ')   //遇到回车则停止输入  
			break;
	}
	BNode *root = build(0, i - 1, 0, i - 1);
	Travel(root);
	system("pause");
	return 0;
}