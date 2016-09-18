#include<iostream> 
using namespace std;
int stackNum(int n, int pop, int push) 
{
	if(push == n)return 1;
	if(push < pop)return 0;
	else if(push == pop) return stackNum(n, pop, push + 1);
	else if (pop < push) 
	{
		int num1 = 0;
		int num2 = 0;
		num1 = stackNum(n, pop + 1, push);
		num2 = stackNum(n, pop, push + 1);
		return num1 + num2;
	}
}
int main() {
	int n;
	cin >> n;
	cout << stackNum(n, 0, 0) << endl;
	system("pause");
	return 0;
}