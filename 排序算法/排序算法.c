//#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


//插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];

		while (end >= 0)
		{
			if (tmp < a[end])
			{

				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
	
}

//希尔排序
void ShellSort(int* a, int n)
{
	int gap = n / 3 + 1; //根据数组长度分大小
	while (gap > 1) //最后一次跳出
	{
		for (int i = 0; i < n - gap; i++)  //用i++可以巧妙地运用多组
		{
			int end = i;
			int tmp = a[end + gap];  //插入的数值，间隔gap个
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;  //往前比较
				}
				else
					break;
			}
			//当它最小或者遇到比它大的值时，赋值当前位置
			a[end + gap] = tmp;

		}
		gap = gap / 3 + 1;  //逐渐收缩

	}

}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//选择排序
void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;

	while (left < right)
	{
		int minsort = left, maxsort = left;
		for (int i = left; i <= right; i++)
		{
			if (a[i] > a[maxsort])
			{
				maxsort = i;
			}
			else if (a[i] < a[minsort])
			{
				minsort = i;
			}
		}
		Swap(&a[left], &a[minsort]);
		if (maxsort == left)
		{
			maxsort = minsort;
		}
		Swap(&a[right], &a[maxsort]);
		left++;
		right--;
	}

}

//堆排序-子
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child < n - 1 && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
	
}
//堆排序-母
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1)/2; i >= 0; i--)
	{
		//建堆
		AdjustDown(a, n, i);
	}
	//已经建好
	while (n > 0)
	{
		Swap(&a[0], &a[n - 1]);
		AdjustDown(a, n - 1, 0);
		n--;
	}

}

//冒泡排序
void Bubble(int* a, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		int count = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				count = 1;
			}
		}
		if (count == 0)
			break;
	}
}

//三数取中法
int GetKey(int* a, int left, int right)
{
	int mid = (left + right) >> 1; // 两值/2
	if (a[left] < a[mid]) // 看 left   mid   right 哪个在中间 
	{
		//left < mid ? right
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right; // left < right < mid
	}
	else // (a[left] > a[mid])
	{
		//mid < left ? right
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}

//hoare法快排    ******************************************************
void QuickHoare(int* a, int begin, int end)
{
	//空和1
	if (begin >= end)
		return;

	//三数取中法
	int mid = GetKey(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int key = begin;
	int left = begin, right =end;

	while (left < right)
	{
		//右边先移
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		//再到左边移动
		while (left < right && a[left] <= a[key])
		{
			left++;
		}
		Swap(&a[left], &a[right]);

	}
	Swap(&a[key], &a[left]);
	//给到中间来
	int meet = left;
	//递归   
	// left   mid    right
	QuickHoare(a, begin, meet - 1);
	QuickHoare(a, meet + 1, end);


}



//挖坑法
void QuickDig(int* a, int begin, int end)
{

	if (begin >= end)
		return;
	//挖坑
	int left = begin, right = end;
	int hole = a[left];

	//排序
	while (left < right)
	{
		//先走右
		while (left < right && a[right] >= hole)
			right--;
		a[left] = a[right]; //填坑

		while (left < right && a[left] <= hole)
			left++;
		a[right] = a[left]; //填坑

	}
	a[left] = hole;
	int meet = left;
	//递归 left   meet   right
	QuickDig(a, begin, meet - 1);
	QuickDig(a, meet + 1, end);

}

//快速排序 -- 快排
void QuickSort(int* a, int begin, int end)
{
	//hoare法快排
	QuickHoare(a, begin, end - 1);

	//挖坑法
	//QuickDig(a, begin, end - 1);

}



// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	//printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}


int main()
{

	//int a[] = { 4,5,3 };
	int a[] = { 10,9,8,7,6,5,4,3,2,1,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10 };

	int n = sizeof(a) / sizeof(a[0]);
	// 插入排序
	//InsertSort(a, n);
	// 希尔排序
	//ShellSort(a, n);
	// 选择排序
	//SelectSort(a, n);
	// 堆排序
	//HeapSort(a, n);
	// 冒泡排序
	//Bubble(a, n);
	// 快排
	//QuickSort(a, 0, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	//TestOP();

	return 0;
}