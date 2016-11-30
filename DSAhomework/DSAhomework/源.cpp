#include <stdio.h>
#include<iostream> 
using namespace std;
int m, size;
int str[1001];
int A[1001];
class MinHeap { // 最小堆ADT定义
public:
	int * heapArray; // 存放堆数据的数组
	int CurrentSize; // 当前堆中元素数目
	int MaxSize; // 堆所能容纳的最大元素数目
	void BuildHeap(); // 建堆
	MinHeap(int* array, const int n); // 构造函数,n为最大元素数目
	void SiftDown(int left); // 筛选法
};
void MinHeap::SiftDown(int position) {
	int i = position; //标识父结点
	int j = 2 * i + 1; //标识关键值较小的子结点
	int  temp = heapArray[i]; //保存父结点
	while (j<CurrentSize) { //过筛
		if ((j<CurrentSize - 1) && (heapArray[j]>heapArray[j + 1]))
			j++; //j指向数值较小的子结点
		if (temp>heapArray[j]) {
			heapArray[i] = heapArray[j];
			i = j; j = 2 * j + 1; //向下继续
		}
		else break;
	}
	heapArray[i] = temp;
}
void MinHeap::BuildHeap() {
	for (int i = CurrentSize / 2 - 1; i >= 0; i--) //反复调用筛选函数
		SiftDown(i);
}
MinHeap::MinHeap(int *array, const int n) {
	CurrentSize = n;
	MaxSize = n; //初始化堆容量为n
	heapArray = new int[MaxSize]; //创建堆空间
	for (int i = 0; i<n; i++) {
		heapArray[i] = array[i];
	}
	BuildHeap(); //此处进行堆元素的赋值工作
}
void replacementSelection(int *A) {
	//建立最小值堆
	MinHeap H(A, size);
	int last = size - 1;
	int len = m<last ? m : size;
	for (int i = 0; i<len; i++) {
		cout << H.heapArray[0] << " ";  	//堆的最小值
		if (str[i] >= H.heapArray[0]) 	H.heapArray[0] = str[i];
		else {//否则用last位置记录代替根结点，把r放到last
			H.heapArray[0] = H.heapArray[last];
			H.heapArray[last] = str[i];
			H.CurrentSize--;
			last--;
		}
		if (last != 0)
			H.SiftDown(0);  //堆调整 
	}
}
int main() {
	cin >> m >> size;
	int i;
	for (i = 0; i<m; i++) {
		cin >> str[i];
	}
	for (i = 0; i<size; i++)
		cin >> A[i];
	replacementSelection(A);
	return 0;
}