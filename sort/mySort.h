#pragma once
//避免头文件重定义错误
#ifndef _MYSORT_
#define _MYSORT_
//size of initial array
const int N = 30;
void BubbleSort(int* arr);
void SelectionSort(int* arr);
void InsertionSort(int* arr);
void ShellSort(int* arr);
void MergeSort(int* arr);
void QuickSort(int* arr);
void HeapSort(int* arr);
void CountingSort(int* arr);
#endif // !_MYSORT_

