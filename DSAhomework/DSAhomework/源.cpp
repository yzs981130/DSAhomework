#include <stdio.h> 
#include <iostream> 
using namespace std;

#define MAXNODE 1024 
char NodeInfoSeq[MAXNODE * 2];
char OutputDump[MAXNODE];
typedef struct fake_bt_node
{
	char info;
	struct fake_bt_node *lc;
	struct fake_bt_node *rc;
} fbtn;
fbtn* nStack[MAXNODE];
fbtn* nQueue[MAXNODE * 2]; //front可能推到很后很后，所以队列空间开大一点（front may be late in the nQueue, so the memory is twice bigger） 

fbtn *BuildFakeBinaryTree(int n)
{
	int sp = -1; //栈指针sp，栈空时为-1。栈顶为当前的父结点。（stack pointer, equals -1 when the stack is empty, the top of the stack is the parent of the current node） 

				 //先建立树根结点（set up the root） 
	fbtn *root = new fbtn;
	root->info = NodeInfoSeq[0];
	root->lc = NULL;
	root->rc = NULL;
	//树根结点进栈（push the root into nStack） 
	nStack[++sp] = root;

	for (int i = 2; i < 2 * n; i += 2)
	{
		//根据输入序列新建一个结点（set up a node according to the input sequence） 
		fbtn *temp = new fbtn;
		temp->info = NodeInfoSeq[i];
		temp->lc = NULL;
		temp->rc = NULL;
		//接下来，把这个新结点连在伪满二叉树上（then, connect this node to the "virtual full binary tree"） 
		fbtn *curFa = nStack[sp]; //栈顶结点是当前结点的父亲（the top of nStack is the parent of the current node） 
		if (!curFa->lc) //当前结点是左儿子（the current node is the left child） 
			curFa->lc = temp;
		else if (!curFa->rc && curFa->lc) //当前结点是右儿子（the current node is the right child） 
			curFa->rc = temp;
		else //curFa的左、右儿子都有，说明curFa不是当前结点的父亲结点，那就退栈，找当前结点的父亲结点，且当前结点一定是右儿子 
			 //curFa have both 2 children, which means curFa is not the parent of the current node, so that pop from nStack and find the parent, notice that the current node is now sure to be right child 
		{
			while (nStack[sp]->rc)
				--sp;
			nStack[sp]->rc = temp;
		}
		if (NodeInfoSeq[i + 1] == '0') //如果新结点是内部结点，那么它一定是父亲，要进栈(if the new node is a internal node, then it is sure to be a parent, so push it into nStack) 
			nStack[++sp] = temp;
	}
	return root;
}

void PrintMirrorImage(fbtn *root)
{
	int qf = 0, qr = -1; //分别表示queue front和queue rear(represent queue front and queue rear) 
	int sp = -1;
	int dp = -1; //表示OutputDump(represent OutputDump) 
	fbtn* head;
	nQueue[++qr] = root; //根节点入队(enqueue the root) 
						 //宽度优先遍历(breadth-first traversal) 
	while (qr + 1 != qf)
	{
		head = nQueue[qf++];
		OutputDump[++dp] = head->info;
		//再把head的所有儿子都入队，由于要输出镜像，所以要反向入队，我们借助栈来完成。(let the children of head enqueue, and in order to output the mirror image, we use stack to reverse the child node sequence) 
		if (head->lc) //head是有儿子的(if head has a child node) 
		{
			fbtn *cc = head->lc; //cc指当前的子节点(cc means current child node) 
								 //出栈，入队，使子节点逆序(pop, enqueue, and then we can get the reversed child node sequence) 
			while (cc != NULL)
			{
				nStack[++sp] = cc;
				cc = cc->rc;
			}
			while (sp != -1)
				nQueue[++qr] = nStack[sp--];
		}
	}
	//打印输出序列(print the output sequence) 
	for (int i = 0; i <= dp; i++)
	{
		if (OutputDump[i] != '$')
			cout << OutputDump[i] << ' ';
	}
}

//释放树的内存(free the memory) 
void DeleteFakeBinaryTree(fbtn *root)
{
	if (root != NULL)
	{
		DeleteFakeBinaryTree(root->lc);
		DeleteFakeBinaryTree(root->rc);
		delete root;
		root = NULL;
	}
}

int main()
{
	int n, i = 0;
	char c;
	cin >> n;
	getchar(); //取走数字n后面的换行符(get the line break) 
	while ((c = getchar()) != '\n')
	{
		if (c != ' ')
			NodeInfoSeq[i++] = c;
	}
	fbtn *root = BuildFakeBinaryTree(n);
	PrintMirrorImage(root);
	DeleteFakeBinaryTree(root);
	system("pause");
	return 0;
}