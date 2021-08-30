#include"mySort.h"
#include<cstdlib>
#include <string.h>

//BubbleSort:冒泡排序(10w/25s)
void BubbleSort(int* arr)
{
	int temp;
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1 - i; j++)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}

	//数组规模大的时候优化：若中途数组已经排好序则退出
	//int temp;
	//bool changed;
	//for (int i = 0; i < N - 1; i++)
	//{
	//	changed = false;
	//	for (int j = 0; j < N - 1 - i; j++)
	//		if (arr[j] > arr[j + 1])
	//		{
	//			temp = arr[j + 1];
	//			arr[j + 1] = arr[j];
	//			arr[j] = temp;
	//			changed = true;
	//		}
	//	if (!changed)break;
	//}

}

//SelectionSort:选择排序(10w/8s)
void SelectionSort(int* arr)
{
	int min_i, temp = 0;
	for (int i = 0; i < N - 1; i++)
	{
		min_i = i;
		for (int j = i + 1; j < N; j++)
			if (arr[j] < arr[min_i])min_i = j;
		temp = arr[min_i];
		arr[min_i] = arr[i];
		arr[i] = temp;
	}
}

//InsertionSort:插入排序(10w/5.3s)
void InsertionSort(int* arr)
{
	int temp;
	for (int i = 1; i < N; i++)
	{
		temp = arr[i];
		int j = i - 1;
		for (; j >= 0 && temp < arr[j]; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

//ShellSort:希尔排序(10w/0.02s 20w/0.04s)
void ShellSort(int* arr)
{
	void GapInsertionSort(int* arr, int stpos, int gap);
	int gap = N / 2;
	while (gap > 0)
	{
		for (int i = 0; i < gap; i++)
			GapInsertionSort(arr, i, gap);
		gap = gap / 2;
	}
}
//GapInsertSort:small intervbal insertion Sort(for ShellSort)
void GapInsertionSort(int* arr, int stpos, int gap)
{
	for (int i = gap + stpos; i < N; i += gap)
	{
		int temp = arr[i];
		int j = i - gap;
		for (; j >= 0 && temp < arr[j]; j -= gap)
		{
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = temp;
	}
}

//MergeSort:递归法(自顶向下)归并排序(10w/0.014s 20w/0.028s)
void MergeSort(int* arr)
{
	void Merge(int* arr, int St, int Ed);
	Merge(arr, 0, N - 1);
}
//复制数组,用于拷贝原数组的某一片段
int cpArr[N] = { 0 };
//Merge:for MergeSort
void Merge(int* arr, int St, int Ed)
{
	if (Ed - St < 1)return;
	if (Ed - St == 1) {
		if (arr[St] > arr[Ed]) {
			int temp = arr[St];
			arr[St] = arr[Ed];
			arr[Ed] = temp;
		}
		return;
	}

	//分割
	int Md = (Ed - St) / 2 + St;
	Merge(arr, St, Md);
	Merge(arr, Md + 1, Ed);

	//归并
	memcpy(cpArr + St, arr + St, sizeof(int) * (Ed - St + 1));
	int l = St, r = Md + 1, pos = St;
	while (pos <= Ed)
	{
		if (l <= Md && r <= Ed)
		{
			if (cpArr[l] <= cpArr[r])arr[pos++] = cpArr[l++];
			else arr[pos++] = cpArr[r++];
		}
		else if (l > Md && r <= Ed)
		{
			arr[pos++] = cpArr[r++];
		}
		else if (l <= Md && r > Ed)
		{
			arr[pos++] = cpArr[l++];
		}
	}
}

//DMergeSort:非递归法(自底向上)归并排序(10w/0.14 20w/0.027s)
void DMergeSort(int* arr)
{
	void DMerge(int* arr, int St, int Md, int Ed);
	int size = 1;
	while (size <= N)
	{
		for (int i = 0; i < N; i += (2 * size))
		{
			DMerge(arr, i, i + size - 1, (N - 1) < (i + 2 * size - 1) ? (N - 1) : (i + 2 * size - 1));
		}
		size += size;
	}
}
int DcpArr[N] = { 0 };
void DMerge(int* arr, int St, int Md, int Ed)
{
	//int Md=(Ed-St)/2+St 错误 Md不可通过计算得来,否则会漏排
	int l = St, r = Md + 1, pos = St;
	memcpy(DcpArr + St, arr + St, sizeof(int) * (Ed - St + 1));
	while (pos <= Ed)
	{
		if (l <= Md && r <= Ed)
		{
			if (DcpArr[l] < DcpArr[r])arr[pos++] = DcpArr[l++];
			else arr[pos++] = DcpArr[r++];
		}
		else if (l > Md && r <= Ed)
		{
			arr[pos++] = DcpArr[r++];
		}
		else if (l <= Md && r > Ed)
		{
			arr[pos++] = DcpArr[l++];
		}
	}
}

//QuickSort:快速排序(10w/0.012s 20w/0.026s) 
void QuickSort(int* arr)
{
	void _quickSort(int* arr, int l, int r);
	_quickSort(arr, 0, N - 1);
}
//_quickSort:for QuickSort
void _quickSort(int* arr, int l, int r)
{
	int Partition(int* arr, int l, int r);
	if (l < r) {
		int m = Partition(arr, l, r);
		_quickSort(arr, l, m - 1);
		_quickSort(arr, m + 1, r);
	}
}
//Partition:split the array and return index of the medium value
int Partition(int* arr, int l, int r)
{
	int i = l, j = r + 1;
	int x = arr[l];
	while (true) {
		while (arr[++i] < x&& i < r);
		while (arr[--j] > x);
		if (i >= j)break;
		//交换ij位置的值
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	arr[l] = arr[j];
	arr[j] = x;
	return j;
}

//HeapSort:堆排序(10w/0.02s 20w/0.043s)
void HeapSort(int* arr)
{
	void max_heapify(int* arr, int start, int end);
	for (int i = N / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, N - 1);
	for (int j = N - 1; j > 0; j--)
	{
		int temp = arr[0];
		arr[0] = arr[j];
		arr[j] = temp;
		max_heapify(arr, 0, j - 1);

	}
}
//max_heapify:to create a max heap;
void max_heapify(int* arr, int start, int end)
{
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end)
	{
		if (son + 1 <= end && arr[son] < arr[son + 1])
			son++;
		if (arr[dad] > arr[son])
			return;
		else
		{
			int temp = arr[dad];
			arr[dad] = arr[son];
			arr[son] = temp;
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

//CoutingSort:计数排序(10w/0.001s 20w/0.002s)
void CountingSort(int* arr)
{
	//统计最大最小值
	int min = arr[0], max = arr[0];
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < min)min = arr[i];
		if (arr[i] > max)max = arr[i];
	}
	int Len = max - min + 1;
	//给计数数组分配空间并初始化
	int* count_arr = (int*)malloc(sizeof(int) * Len);
	for (int i = 0; i < Len; i++)
		count_arr[i] = 0;
	//统计原数组
	for (int i = 0; i < N; i++)
		count_arr[arr[i] - min]++;
	//还原排序好的数组(两种方式)
	for (int i = 0, j = 0; j < N; j++)
	{
		while (count_arr[i] <= 0)i++;
		arr[j] = i + min;
		count_arr[i]--;
	}
	/*for (int i = 0,j=0; i < Len; i++)
	{
		while (count_arr[i] > 0)
		{
			arr[j++] = i + min;
			count_arr[i]--;
		}
	}*/
}
