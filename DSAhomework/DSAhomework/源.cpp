#include <iostream> 
#include <queue> 
using namespace std;

struct node {
	char val;
	node *child[26]; ///子节点(child node) 
	node(char c) { //构造函数(constructor) 
		val = c;
		for (int i = 0; i < 26; i++)
			child[i] = NULL;
	}
	~node() { //析构函数(destructor) 
		for (int i = 0; i < 26; i++)
			delete child[i];
	}
};
void create(node *&root) {
	queue <node *>qRoot;
	queue<int>qSeq;
	node *temp;
	char ch;
	int i = 0;
	int degree = 0;//树的度
	int childNum;
	cin >> ch >> childNum;
	node *tempHead = new node (ch);
	root = new node(ch);
	qRoot.push(root);
	qSeq.push(childNum);
	while (!qRoot.empty()) {
		while (degree == i) {
			if (qRoot.empty())
				return;
			degree = qSeq.front();
			qSeq.pop();
			tempHead = qRoot.front();
			qRoot.pop();
			i = 0;
		}
		cin >> ch >> childNum;
		temp = new node(ch);
		qRoot.push(temp);
		qSeq.push(childNum);
		tempHead->child[i] = temp;
		i++;
	}
}

void post(node *root) { //后根遍历(post-order traversal) 
	for (int i = 0; (i < 26) && root->child[i]; i++)
		post(root->child[i]);
	cout << root->val << ' ';
}

int main() {
	int n;
	node * root;
	cin >> n;
	while (n--) { //处理n棵树(deal with n trees) 
		create(root);
		post(root);
	}
	system("pause");
	return 0;
}