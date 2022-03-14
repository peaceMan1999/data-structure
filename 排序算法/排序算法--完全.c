//#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

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

		for (int i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}

	//最后一次移动
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= 1;  //往前比较
			}
			else
				break;
		}
		//当它最小或者遇到比它大的值时，赋值当前位置
		a[end + 1] = tmp;
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
		if (maxsort == left)  //判断避免max赋予了min的值
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

//******************************************************
//hoare法快排    
int QuickHoare(int* a, int left, int right)
{
	//三数取中法
	int mid = GetKey(a, left, right);
	Swap(&a[left], &a[mid]);

	int key = left;

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

	return meet;

}

//前后指针法
int QuickPoint(int* a, int left, int right)
{
	int prev = left, cur = prev + 1;
	//三数取中
	//int mid = GetKey(a, left, right);
	//Swap(&a[mid], &a[prev]);
	int key = prev;

	while (cur <= right)
	{
		if (a[key] > a[cur] && ++prev != cur) //避免原地TP
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[key], &a[prev]);

	return prev;
}

//挖坑法
int QuickDig(int* a, int left, int right)
{
	//挖坑
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

	return meet;

}

//非递归快排 -- 迭代,需要用到Stack栈
void QuickSortNonR(int* a, int left, int right)
{
	stack st;
	StackInit(&st);
	//先存左右区间
	StackPush(&st, left);
	StackPush(&st, right);
	//空了就代表排序完成，没空继续
	while (!StackEmpty(&st))
	{
		int end = StackTop(&st);
		StackPop(&st);

		int begin = StackTop(&st);
		StackPop(&st);

		int key = QuickHoare(a, begin, end);

		if (begin < key - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, key - 1);
		}

		if (end > key + 1)
		{
			StackPush(&st, key + 1);
			StackPush(&st, end);
		}

	}

	StackDistroy(&st);
}

//快排
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int keyi = QuickPoint(a, begin, end);

	// [begin, keyi-1] keyi [keyi+1, end]
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);

	//// 1、如果这个子区间是数据较多，继续选key单趟，分割子区间分治递归
	//// 2、如果这个子区间是数据较小，再去分治递归不太划算
	//if (end - begin > 20)
	//{
	//	int keyi = QuickPoint(a, begin, end);

	//	// [begin, keyi-1] keyi [keyi+1, end]
	//	QuickSort(a, begin, keyi - 1);
	//	QuickSort(a, keyi + 1, end);
	//}
	//else
	//{
	//	//HeapSort(a + begin, end - begin + 1);
	//	InsertSort(a + begin, end - begin + 1);
	//}
}

//******************************************************

//归并操作
void _Merge(int* a, int* tmp, int begin1, int end1, int begin2, int end2)
{

	int i = begin1, j = i;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	for (; j <= end2; j++)
	{
		a[j] = tmp[j];
	}
}

//子函数
void _MergeSort(int* a,int *tmp, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int begin1 = left, begin2 = mid + 1, end1 = mid, end2 = right;
	_Merge(a, tmp, begin1, end1, begin2, end2);
}

//归并排序
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc false");
		return;
	}

	int left = 0; int right = n - 1;
	_MergeSort(a, tmp, left, right);


	free(tmp);
}

//非递归归并排序
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc false");
		return;
	}
	int left = 0, right = n - 1;
	int gap = 1;   //间隔为 1 ，再往后递增

	while (gap < n)
	{
		for (int j = 0; j < right; j += gap*2)
		{
			//[j, j+gap-1] [j+gap, j+gap*2-1]
			int begin1 = j, begin2 = j + gap, end1 = j + gap - 1, end2 = j + gap * 2 - 1;
			//考虑多种情况
			//1,前区间结尾小于right 和 只有前区间，没到后区间
			if (end1 >= right)
				break;
			//2，有前区间，但后区间小于right的
			if (end2 > right)
			{
				end2 = right;
			}

			_Merge(a, tmp, begin1, end1, begin2, end2);

		}

		gap *= 2;
	}

}

//计数排序
void CountSort(int* a, int n)
{
	int gap = 0, min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//求出最大值和最小值的差，相对映射
	gap = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * gap);
	memset(count, 0 ,sizeof(int) * gap);
	
	//标记到count上
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	//赋值回去
	int i = 0;
	for (int j = 0; j < gap; j++)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}

	free(count);

}


int main()
{

	//int a[] = { 9,9,5,8,7,4,6,10 };
	int a[] = { 10,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	//int a[] = { 10,9,8,7,6,5,4,3,2,1,0};

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
	Bubble(a, n);
	// 快排
	//QuickSort(a, 0, n - 1);
	//非递归快排
	//QuickSortNonR(a, 0, n - 1);
	//归并排序
	//MergeSort(a, n);
	//非递归归并
	//MergeSortNonR(a, n);
	//计数排序
	//CountSort(a, n);


	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	//TestOP();

	return 0;
}