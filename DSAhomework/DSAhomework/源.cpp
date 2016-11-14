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
fbtn* nQueue[MAXNODE * 2]; //front�����Ƶ��ܺ�ܺ����Զ��пռ俪��һ�㣨front may be late in the nQueue, so the memory is twice bigger�� 

fbtn *BuildFakeBinaryTree(int n)
{
	int sp = -1; //ջָ��sp��ջ��ʱΪ-1��ջ��Ϊ��ǰ�ĸ���㡣��stack pointer, equals -1 when the stack is empty, the top of the stack is the parent of the current node�� 

				 //�Ƚ���������㣨set up the root�� 
	fbtn *root = new fbtn;
	root->info = NodeInfoSeq[0];
	root->lc = NULL;
	root->rc = NULL;
	//��������ջ��push the root into nStack�� 
	nStack[++sp] = root;

	for (int i = 2; i < 2 * n; i += 2)
	{
		//�������������½�һ����㣨set up a node according to the input sequence�� 
		fbtn *temp = new fbtn;
		temp->info = NodeInfoSeq[i];
		temp->lc = NULL;
		temp->rc = NULL;
		//��������������½������α���������ϣ�then, connect this node to the "virtual full binary tree"�� 
		fbtn *curFa = nStack[sp]; //ջ������ǵ�ǰ���ĸ��ף�the top of nStack is the parent of the current node�� 
		if (!curFa->lc) //��ǰ���������ӣ�the current node is the left child�� 
			curFa->lc = temp;
		else if (!curFa->rc && curFa->lc) //��ǰ������Ҷ��ӣ�the current node is the right child�� 
			curFa->rc = temp;
		else //curFa�����Ҷ��Ӷ��У�˵��curFa���ǵ�ǰ���ĸ��׽�㣬�Ǿ���ջ���ҵ�ǰ���ĸ��׽�㣬�ҵ�ǰ���һ�����Ҷ��� 
			 //curFa have both 2 children, which means curFa is not the parent of the current node, so that pop from nStack and find the parent, notice that the current node is now sure to be right child 
		{
			while (nStack[sp]->rc)
				--sp;
			nStack[sp]->rc = temp;
		}
		if (NodeInfoSeq[i + 1] == '0') //����½�����ڲ���㣬��ô��һ���Ǹ��ף�Ҫ��ջ(if the new node is a internal node, then it is sure to be a parent, so push it into nStack) 
			nStack[++sp] = temp;
	}
	return root;
}

void PrintMirrorImage(fbtn *root)
{
	int qf = 0, qr = -1; //�ֱ��ʾqueue front��queue rear(represent queue front and queue rear) 
	int sp = -1;
	int dp = -1; //��ʾOutputDump(represent OutputDump) 
	fbtn* head;
	nQueue[++qr] = root; //���ڵ����(enqueue the root) 
						 //������ȱ���(breadth-first traversal) 
	while (qr + 1 != qf)
	{
		head = nQueue[qf++];
		OutputDump[++dp] = head->info;
		//�ٰ�head�����ж��Ӷ���ӣ�����Ҫ�����������Ҫ������ӣ����ǽ���ջ����ɡ�(let the children of head enqueue, and in order to output the mirror image, we use stack to reverse the child node sequence) 
		if (head->lc) //head���ж��ӵ�(if head has a child node) 
		{
			fbtn *cc = head->lc; //ccָ��ǰ���ӽڵ�(cc means current child node) 
								 //��ջ����ӣ�ʹ�ӽڵ�����(pop, enqueue, and then we can get the reversed child node sequence) 
			while (cc != NULL)
			{
				nStack[++sp] = cc;
				cc = cc->rc;
			}
			while (sp != -1)
				nQueue[++qr] = nStack[sp--];
		}
	}
	//��ӡ�������(print the output sequence) 
	for (int i = 0; i <= dp; i++)
	{
		if (OutputDump[i] != '$')
			cout << OutputDump[i] << ' ';
	}
}

//�ͷ������ڴ�(free the memory) 
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
	getchar(); //ȡ������n����Ļ��з�(get the line break) 
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