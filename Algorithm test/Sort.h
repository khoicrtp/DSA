#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;

template <class T>
//void HoanVi(T& a, T& b)
//{
//	T x = a;
//	a = b;
//	b = x;
//}

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

void print(int a[], int n);

void selectionSort(int*& a, int n);
void selectionSortSet(int n);

void insertionSort(int arr[], int n);
void insertionSortSet(int n);

int binarySearch(int a[], int key, int l, int r);
void binaryInsertionSort(int a[], int n);
void binaryInsertionSortSet(int n);

void bubbleSort(int arr[], int n);
void bubbleSortSet(int n);

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void heapSortSet(int n);

void merge(int a[], int left, int mid, int right);
void mergeSort(int a[], int left, int right);
void mergeSortSet(int n);

int partition(int arr[], int low, int high);
void quickSort(int arr[], int l, int r);
void quickSortSet(int n);

int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixSort(int arr[], int n);
void radixSortSet(int n);

#endif // !_SORT_H_








