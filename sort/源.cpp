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
	//Ã°ÅÝÅÅÐò
	//BubbleSort(srcArr);
	//Ñ¡ÔñÅÅÐò
	//SelectionSort(srcArr);
	//²åÈëÅÅÐò
	//InsertionSort(srcArr);
	//Ï£¶ûÅÅÐò
	//ShellSort(srcArr);
	//µÝ¹é·¨¹é²¢ÅÅÐò(×Ô¶¥ÏòÏÂ)
	//MergeSort(srcArr);
	//·ÇµÝ¹é·¨¹é²¢ÅÅÐò(×Ôµ×ÏòÉÏ)
	//DMergeSort(srcArr);
	//¿ìËÙÅÅÐò
	//QuickSort(srcArr);
	//¶ÑÅÅÐò
	//HeapSort(srcArr);
	//¼ÆÊýÅÅÐò
	//CountingSort(srcArr);
	Et = clock();
	DisArray(srcArr);
	cout <<"Time consuming:"<< (double)(Et-St) / CLOCKS_PER_SEC <<"s"<< endl;
	return 0;
}