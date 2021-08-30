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
	//冒泡排序
	//BubbleSort(srcArr);
	//选择排序
	//SelectionSort(srcArr);
	//插入排序
	//InsertionSort(srcArr);
	//希尔排序
	//ShellSort(srcArr);
	//递归法归并排序(自顶向下)
	//MergeSort(srcArr);
	//非递归法归并排序(自底向上)
	//DMergeSort(srcArr);
	//快速排序
	//QuickSort(srcArr);
	//堆排序
	//HeapSort(srcArr);
	//计数排序
	//CountingSort(srcArr);
	Et = clock();
	DisArray(srcArr);
	cout <<"Time consuming:"<< (double)(Et-St) / CLOCKS_PER_SEC <<"s"<< endl;
	return 0;
}
