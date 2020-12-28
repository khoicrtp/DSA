
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

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

void bubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n-1; j > i; j--)
		{
			if (a[j] < a[j-1])
			{
				swap(a[j], a[j-1]);
			}
		}
	}
}

void insertSort(int* a, int n)
{
	int key, j;
	for (int i = 0; i < n; i++)
	{
		key = a[i];
		for (j = i - 1; j > -1; j--)
		{
			if (key > a[j])
			{
				break;
			}
			a[j+1] = a[j];
		}
		a[j + 1] = key;
	}
}

int binarySearch(int* a, int l, int r, int key)
{
	int mid = (l + r) / 2;
	if (l >= r)
	{
		return (a[l] < key) ? l + 1 : l;
	}
	if (a[mid] > key)
	{
		return binarySearch(a, l, mid-1, key);
	}
	else
	{
		return binarySearch(a, mid + 1, r, key);
	}
}

void binInsert(int* a, int n)
{
	int key, j;
	for (int i = 0; i < n; i++)
	{
		j = i - 1;
		key = a[i];

		int loc = binarySearch(a, 0, j, key);
		
		for (j = i-1; j >= loc; j--)
		{
			a[j + 1] = a[j];
		}

		a[j+1] = key;
	}
}

void selectionSort(int* a, int n)
{
	int min;
	for (int i = 0; i < n-1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		swap(a[min], a[i]);
	}
}

void merge(int* a, int l, int r, int mid)
{
	int* temp = new int[r - l + 1];

	int i = l;
	int j = mid + 1;

	for (int k = 0; k < r - l + 1; k++)
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
			while (j < r+1) {
				k++;
				temp[k] = a[j];
				j++;
			}
			break;
		}

		if (j == r+1)
		{
			while (i < mid + 1) {
				k++;
				temp[k] = a[i];
				i++;
			}
			break;
		}
	}
	
	for (int k = 0; k <= r - l; k++)
		a[l + k] = temp[k];
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
		merge(a, left, right, mid);
	}
}

void bub(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n-1; j > i; j--)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

void ins(int* a, int n)
{
	int key, j;
	for (int i = 0; i < n; i++)
	{
		key = a[i];
		
		for (j = i - 1; j > -1; j--) {
			if (key > a[j])
			{
				break;
			}
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

int binS(int* a, int l, int r, int key)
{
	if (l >= r)
		return (a[l]>key) ? l+1 : l ;
	int mid = (l + r) / 2;
	if (key < a[mid])
	{
		return binS(a, l, mid - 1, key);
	}
	else
	{
		return binS(a, mid + 1, r, key);
	}
}

void insB(int* a, int n)
{
	int loc, key, j;

	for (int i = 1; i < n; i++)
	{
		loc = binS(a, 0, i - 1, a[i]);
		key = a[i];

		for (j = i - 1; j > loc; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}




int main()
{
	int n = 3000;
	int* a=new int[n];

	GenerateRandomData(a, n);

	//bubbleSort(a, n);
	//print(a, n);

	//insertSort(a, n);
	//print(a, n);

	//binInsert(a, n);
	//print(a, n);

	//selectionSort(a, n);
	//print(a, n);

	//mergeSort(a, 0, n);
	//print(a, n);

	insB(a, n);
	print(a, n);
}