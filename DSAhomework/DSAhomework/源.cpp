#include <stdio.h>
#include<iostream> 
using namespace std;
int m, size;
int str[1001];
int A[1001];
class MinHeap { // ��С��ADT����
public:
	int * heapArray; // ��Ŷ����ݵ�����
	int CurrentSize; // ��ǰ����Ԫ����Ŀ
	int MaxSize; // ���������ɵ����Ԫ����Ŀ
	void BuildHeap(); // ����
	MinHeap(int* array, const int n); // ���캯��,nΪ���Ԫ����Ŀ
	void SiftDown(int left); // ɸѡ��
};
void MinHeap::SiftDown(int position) {
	int i = position; //��ʶ�����
	int j = 2 * i + 1; //��ʶ�ؼ�ֵ��С���ӽ��
	int  temp = heapArray[i]; //���游���
	while (j<CurrentSize) { //��ɸ
		if ((j<CurrentSize - 1) && (heapArray[j]>heapArray[j + 1]))
			j++; //jָ����ֵ��С���ӽ��
		if (temp>heapArray[j]) {
			heapArray[i] = heapArray[j];
			i = j; j = 2 * j + 1; //���¼���
		}
		else break;
	}
	heapArray[i] = temp;
}
void MinHeap::BuildHeap() {
	for (int i = CurrentSize / 2 - 1; i >= 0; i--) //��������ɸѡ����
		SiftDown(i);
}
MinHeap::MinHeap(int *array, const int n) {
	CurrentSize = n;
	MaxSize = n; //��ʼ��������Ϊn
	heapArray = new int[MaxSize]; //�����ѿռ�
	for (int i = 0; i<n; i++) {
		heapArray[i] = array[i];
	}
	BuildHeap(); //�˴����ж�Ԫ�صĸ�ֵ����
}
void replacementSelection(int *A) {
	//������Сֵ��
	MinHeap H(A, size);
	int last = size - 1;
	int len = m<last ? m : size;
	for (int i = 0; i<len; i++) {
		cout << H.heapArray[0] << " ";  	//�ѵ���Сֵ
		if (str[i] >= H.heapArray[0]) 	H.heapArray[0] = str[i];
		else {//������lastλ�ü�¼�������㣬��r�ŵ�last
			H.heapArray[0] = H.heapArray[last];
			H.heapArray[last] = str[i];
			H.CurrentSize--;
			last--;
		}
		if (last != 0)
			H.SiftDown(0);  //�ѵ��� 
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