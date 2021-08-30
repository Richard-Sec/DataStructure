#include<iostream>
#include<ctime>
#include"mySort.h"
using namespace std;
//left and right border of random numbers
const int Lp = 0;
const int Rp = 100;
clock_t St, Et;

//CreArray:create a random array
void CreArray(int(&arr)[N])
{
	srand(time(0));
	for (int i = 0; i < N; i++)
		arr[i] = rand() % (Rp - Lp + 1) + Lp;
}

//DisArray:display the array content
void DisArray(int* arr)
{
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int srcArr[N] = {0};
	CreArray(srcArr);
	DisArray(srcArr);
	St = clock();
	//ð������
	//BubbleSort(srcArr);
	//ѡ������
	//SelectionSort(srcArr);
	//��������
	//InsertionSort(srcArr);
	//ϣ������
	//ShellSort(srcArr);
	//�ݹ鷨�鲢����(�Զ�����)
	//MergeSort(srcArr);
	//�ǵݹ鷨�鲢����(�Ե�����)
	//DMergeSort(srcArr);
	//��������
	//QuickSort(srcArr);
	//������
	//HeapSort(srcArr);
	//��������
	//CountingSort(srcArr);
	Et = clock();
	DisArray(srcArr);
	cout <<"Time consuming:"<< (double)(Et-St) / CLOCKS_PER_SEC <<"s"<< endl;
	return 0;
}