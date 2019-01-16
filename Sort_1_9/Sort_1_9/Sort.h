#pragma once
#include<stdio.h>
#include<string.h>


void InsertSort(int* a, int n);
void Swap(int* pa, int* pb);
void ShellSort(int* a, int n);
void SelectSort(int* a, int n);
void HeapSort(int* a, int n);
void BubbleSort(int* a, int n);
void QuickSort(int* a, int left, int right);
void QuickSortNonP(int* a, int left, int right);
void QuickSortOP(int* a, int left, int right);
void MergeSort(int* a, int n);


void SortTest();
//
//void InsertSortTest();
//void ShellSortTest();
//void SelectSortTest();
//void HeapSortTest();
//void BubbleSortTest();
//void QuickSortTest();
//void QuickSortNonPTest();
//void QuickSortOPTest();

