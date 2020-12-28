#include "Sort.h"

void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		swap(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	
		GenerateRandomData(a, n);
		break;
	case 1:	
		GenerateSortedData(a, n);
		break;
	case 2:	
		GenerateReverseData(a, n);
		break;
	case 3:	
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}

//SELECTION

void selectionSort(int*& a, int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				swap(a[j], a[min]);
			}
		}
	}
}

void selectionSortSet(int n)
{
	int* a = new int[n];
	//random
	GenerateRandomData(a, n);
	clock_t tic = clock();
	selectionSort(a, n);
	//print(a, n);
	clock_t toc = clock();
	cout << "Random " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateSortedData(a, n);
	tic = clock();
	selectionSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "Sorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateReverseData(a, n);
	tic = clock();
	selectionSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "Reverse " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateNearlySortedData(a, n);
	tic = clock();
	selectionSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "NearlySorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	delete a;
	//
}

//INSERTION

void insertionSort(int a[], int n)
{
	int key, j;
	for (int i = 0; i < n; i++)
	{
		key = a[i];
		for (j = i - 1; j > -1; j--)
		{
			if (key > a[j]) {
				break;
			}
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

void insertionSortSet(int n)
{
	int* a = new int[n];
	//random
	GenerateRandomData(a, n);
	clock_t tic = clock();
	insertionSort(a, n);
	//print(a, n);
	clock_t toc = clock();
	cout << "Random " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateSortedData(a, n);
	tic = clock();
	insertionSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "Sorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateReverseData(a, n);
	tic = clock();
	insertionSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "Reverse " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateNearlySortedData(a, n);
	tic = clock();
	insertionSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "NearlySorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	delete a;
	//
}

//BINARY INSERTION

int binarySearch(int a[], int key, int l, int r)
{
	if (r <= l)
	{
		return (key > a[l] ? l + 1 : l);
	}

	int mid = (l + r) / 2;

	if (a[mid] < key)
	{
		return binarySearch(a, key, mid + 1, r);
	}
	else
	{
		return binarySearch(a, key, l, mid - 1);
	}
}

void binaryInsertionSort(int a[], int n)
{
	int loc, key, j;

	for (int i = 1; i < n; i++)
	{
		j = i - 1;
		key = a[i];

		loc = binarySearch(a, key, 0, j);

		for (j = i - 1; j >= loc; j--)
		{
			a[j + 1] = a[j];
		}

		a[j + 1] = key;
	}
}

void binaryInsertionSortSet(int n)
{
	int* a = new int[n];
	//random
	GenerateRandomData(a, n);
	clock_t tic = clock();
	binaryInsertionSort(a, n);
	//print(a, n);
	clock_t toc = clock();
	cout << "Random " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateSortedData(a, n);
	tic = clock();
	binaryInsertionSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "Sorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateReverseData(a, n);
	tic = clock();
	binaryInsertionSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "Reverse " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateNearlySortedData(a, n);
	tic = clock();
	binaryInsertionSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "NearlySorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	delete a;
	//
}

//BUBBLE SORT
void bubbleSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
		for (int j = n - 1; j >= i; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}

void bubbleSortSet(int n)
{
	int* a = new int[n];
	//random
	GenerateRandomData(a, n);
	clock_t tic = clock();
	bubbleSort(a, n);
	//print(a, n);
	clock_t toc = clock();
	cout << "Random " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateSortedData(a, n);
	tic = clock();
	bubbleSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "Sorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateReverseData(a, n);
	tic = clock();
	bubbleSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "Reverse " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateNearlySortedData(a, n);
	tic = clock();
	bubbleSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "NearlySorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	delete a;
}

//HEAP SORT
void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[l] > a[largest])
		largest = l;

	if (r < n && a[r] > a[largest])
		largest = r;

	if (largest != i)
	{
		swap(a[i], a[largest]);

		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i > -1; i--)
		heapify(a, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);

		heapify(a, i, 0);
	}
}

void heapSortSet(int n)
{
	int* a = new int[n];
	//random
	GenerateRandomData(a, n);
	clock_t tic = clock();
	heapSort(a, n);
	//print(a, n);
	clock_t toc = clock();
	cout << "Random " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateSortedData(a, n);
	tic = clock();
	heapSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "Sorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateReverseData(a, n);
	tic = clock();
	heapSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "Reverse " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateNearlySortedData(a, n);
	tic = clock();
	heapSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "NearlySorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	delete a;
}

//MERGE SORT

void merge(int a[], int left, int mid, int right)
{
	int* temp= new int[right - left + 1];
	int i = left;
	int j = mid + 1;

	for (int k = 0; k <= right - left; k++)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			i++;
		}
		else
		{
			temp[k] = a[j];
			j++;
		}

		if (i == mid + 1)
		{
			while (j <= right)
			{
				k++;
				temp[k] = a[j];
				j++;
			}
			break;
		}

		if (j == right + 1)
		{
			while (i <= mid)
			{
				k++;
				temp[k] = a[i];
				i++;
			}
			break;
		}
	}

	for (int k = 0; k <= right - left; k++)
		a[left + k] = temp[k];
	delete temp;
}

void mergeSort(int a[], int left, int right)
{
	if (right > left)
	{
		int mid;
		mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

void mergeSortSet(int n)
{
	int* a = new int[n];
	//random
	GenerateRandomData(a, n);
	clock_t tic = clock();
	mergeSort(a, 0, n);
	//print(a, n);
	clock_t toc = clock();
	cout << "Random " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateSortedData(a, n);
	tic = clock();
	mergeSort(a, 0, n);
	//print(a, n);
	toc = clock();
	cout << "Sorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateReverseData(a, n);
	tic = clock();
	mergeSort(a, 0, n);
	//print(a, n);
	toc = clock();
	cout << "Reverse " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateNearlySortedData(a, n);
	tic = clock();
	mergeSort(a, 0, n);
	//print(a, n);
	toc = clock();
	cout << "NearlySorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;
}

//QUICK SORT

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int left = low;

	int right = high;
	while (true) {
		while (left <= right && arr[left] < pivot)
			left++;

		while (right >= left && arr[right] > pivot)
			right--;

		if (left >= right)
			break;

		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
}

void quickSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int pi = partition(arr, l, r);

		quickSort(arr, l, pi - 1);
		quickSort(arr, pi + 1, r);
	}
}

void quickSortSet(int n)
{
	int* a = new int[n];
	//random
	GenerateRandomData(a, n);
	clock_t tic = clock();
	quickSort(a, 0, n-1);
	print(a, n);
	clock_t toc = clock();
	cout << "Random " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateSortedData(a, n);
	tic = clock();
	quickSort(a, 0, n-1);
	//print(a, n);
	toc = clock();
	cout << "Sorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateReverseData(a, n);
	tic = clock();
	quickSort(a, 0, n-1);
	//print(a, n);
	toc = clock();
	cout << "Reverse " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	GenerateNearlySortedData(a, n);
	tic = clock();
	quickSort(a, 0, n);
	//print(a, n);
	toc = clock();
	cout << "NearlySorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

	//delete a;
}

//RADIX SORT

int getMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void countSort(int arr[], int n, int exp)
{
	int* output = new int[n];
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
	int m = getMax(arr, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

void radixSortSet(int n)
{
	int* a = new int[n];
	//random
	GenerateRandomData(a, n);
	clock_t tic = clock();
	radixSort(a, n);
	//print(a, n);
	clock_t toc = clock();
	cout << "Random " << n << " Elapsed: " << (double)(toc - tic) * 1000 / CLOCKS_PER_SEC << " mili seconds" << endl;

	GenerateSortedData(a, n);
	tic = clock();
	radixSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "Sorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " mili seconds" << endl;

	GenerateReverseData(a, n);
	tic = clock();
	radixSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "Reverse " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " mili seconds" << endl;

	GenerateNearlySortedData(a, n);
	tic = clock();
	radixSort(a, n);
	//print(a, n);
	toc = clock();
	cout << "NearlySorted " << n << " Elapsed: " << (double)(toc - tic) / CLOCKS_PER_SEC << " mili seconds" << endl;

	//delete a;
}