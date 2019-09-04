#include <stdio.h>	
#include <time.h>
#include <string.h>
#include <stdlib.h>

int BinarySearch(int key, int a[],int length)
{
	int low, mid, high;
	high = length - 1;
	low = 0;
	mid = (low + high) / 2;
	while (a[mid] != key && high-low>=0 )
	{
		if (key > a[mid])
		{
			low = mid + 1;
		}
		else if (key < a[mid])
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
		mid = (low + high) / 2;
	}
	if (key == a[mid])
		return mid;
	else
		return -1;
}

void select_sort(int a[],int len)
{
	int i, j;
	for (i = 0; i < len; i++)
		for (j = i; j < len-1; j++)
		{
			int temp;
			if (a[i] > a[j + 1])
			{
				temp = a[i];
				a[i] = a[j + 1];
				a[j + 1] = temp;
			}
		}
}

void insert_sort(int a[], int len)
{
	int i,j;
	
	for (i = 1; i < len; i++)
	{
		for (j = i; j >0 && (a[j]<a[j-1]); j--)
		{
			int temp;
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
		}
	}

}

void shell_sort(int a[], int len)
{
	int i,j;
	int h = 1;
	while (h < len / 3) h = 3 * h + 1;

	for (i = 1; i < len; i++)
	{
		for (j = i; j > 0 && (a[j] < a[j - 1]); j--)
		{
			int temp;
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
		}
	}
}

void generate_rand_int_arr(int arr[], int len)
{
	srand(time(NULL));
	for (int i = 0; i < len; i++)
	{
		arr[i] = rand() % 1000;
	}
}

typedef void (*sort_func)(int *, int);
void test_sort_efficient(int arr[],sort_func func1, sort_func func2,int len)
{
	clock_t start,end,mid;
	double time1, time2;
	int *temp =(int*)malloc(sizeof(int)*len);
	memcpy(temp, arr, sizeof(int)*len);

	start = clock();
	func1(arr, len);
	mid = clock();
	time1 = (double)(mid - start) / CLOCKS_PER_SEC;

	func2(temp, len);
	end = clock();
	time2 = (double)(end - mid) / CLOCKS_PER_SEC;
	printf("time1=%fs time2=%fs \n", time1, time2);
}

int main(void)
{
	//int a[11] = { 1,3,4,5,6,8,9,10,13,15 ,20};
	//int b[11] = { 6,5,4,2,64,646,43,47,8,10,212 };
	/*int ret;
	ret = BinarySearch(11, a,11);
	printf("ret = %d", ret);*/
#define LEN 1000
	int a[LEN];
	//insert_sort(b, 11);
	//for (int i = 0; i < 11;i++)
		//printf("%d ",b[i]);
	for (int i = 0; i < 10; i++)
	{
		generate_rand_int_arr(a, LEN);
		test_sort_efficient(a, select_sort, insert_sort, LEN);
	}



	getchar();


}