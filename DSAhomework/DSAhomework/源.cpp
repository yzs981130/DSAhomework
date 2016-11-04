#include<iostream> 
using namespace std;
struct node
{
	int key;
	node *left;
	node *right;
	node(int k)
	{
		key = k;
		left = NULL;
		right = NULL;
	}
};
//向二叉搜索树插入元素(insert an element to the binary search tree) 
void insert(node *root, int n)
{
	if (n<root->key)
	{
		if (root->left == NULL)
			root->left = new node(n);
		else insert(root->left, n);
	}
	else if (n>root->key)
	{
		if (root->right == NULL)
			root->right = new node(n);
		else insert(root->right, n);
	}
}
//前根遍历(get the preorder sequence) 
void preorder(node *root)
{
	if (root == NULL)
		return;
	cout << root->key << ' ';
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	int n;
	cin >> n;
	node *root = new node(n);
	while (cin >> n)
		insert(root, n);
	preorder(root);
	system("pause");
	return 0;
}