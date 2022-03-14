//#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//��������
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

//ϣ������
void ShellSort(int* a, int n)
{
	int gap = n / 3 + 1; //�������鳤�ȷִ�С
	while (gap > 1) //���һ������
	{
		for (int i = 0; i < n - gap; i++)  //��i++������������ö���
		{
			int end = i;
			int tmp = a[end + gap];  //�������ֵ�����gap��
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;  //��ǰ�Ƚ�
				}
				else
					break;
			}
			//������С���������������ֵʱ����ֵ��ǰλ��
			a[end + gap] = tmp;

		}
		gap = gap / 3 + 1;  //������

		for (int i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}

	//���һ���ƶ�
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= 1;  //��ǰ�Ƚ�
			}
			else
				break;
		}
		//������С���������������ֵʱ����ֵ��ǰλ��
		a[end + 1] = tmp;
	}

}


void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//ѡ������
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
		if (maxsort == left)  //�жϱ���max������min��ֵ
		{
			maxsort = minsort;
		}
		Swap(&a[right], &a[maxsort]);
		left++;
		right--;
	}

}

//������-��
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
//������-ĸ
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1)/2; i >= 0; i--)
	{
		//����
		AdjustDown(a, n, i);
	}
	//�Ѿ�����
	while (n > 0)
	{
		Swap(&a[0], &a[n - 1]);
		AdjustDown(a, n - 1, 0);
		n--;
	}

}

//ð������
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

//����ȡ�з�
int GetKey(int* a, int left, int right)
{
	int mid = (left + right) >> 1; // ��ֵ/2
	if (a[left] < a[mid]) // �� left   mid   right �ĸ����м� 
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
//hoare������    
int QuickHoare(int* a, int left, int right)
{
	//����ȡ�з�
	int mid = GetKey(a, left, right);
	Swap(&a[left], &a[mid]);

	int key = left;

	while (left < right)
	{
		//�ұ�����
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		//�ٵ�����ƶ�
		while (left < right && a[left] <= a[key])
		{
			left++;
		}
		Swap(&a[left], &a[right]);

	}
	Swap(&a[key], &a[left]);
	//�����м���
	int meet = left;

	return meet;

}

//ǰ��ָ�뷨
int QuickPoint(int* a, int left, int right)
{
	int prev = left, cur = prev + 1;
	//����ȡ��
	//int mid = GetKey(a, left, right);
	//Swap(&a[mid], &a[prev]);
	int key = prev;

	while (cur <= right)
	{
		if (a[key] > a[cur] && ++prev != cur) //����ԭ��TP
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[key], &a[prev]);

	return prev;
}

//�ڿӷ�
int QuickDig(int* a, int left, int right)
{
	//�ڿ�
	int hole = a[left];

	//����
	while (left < right)
	{
		//������
		while (left < right && a[right] >= hole)
			right--;
		a[left] = a[right]; //���

		while (left < right && a[left] <= hole)
			left++;
		a[right] = a[left]; //���

	}
	a[left] = hole;
	int meet = left;

	return meet;

}

//�ǵݹ���� -- ����,��Ҫ�õ�Stackջ
void QuickSortNonR(int* a, int left, int right)
{
	stack st;
	StackInit(&st);
	//�ȴ���������
	StackPush(&st, left);
	StackPush(&st, right);
	//���˾ʹ���������ɣ�û�ռ���
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

//����
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int keyi = QuickPoint(a, begin, end);

	// [begin, keyi-1] keyi [keyi+1, end]
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);

	//// 1�������������������ݽ϶࣬����ѡkey���ˣ��ָ���������εݹ�
	//// 2�������������������ݽ�С����ȥ���εݹ鲻̫����
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

//�鲢����
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

//�Ӻ���
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

//�鲢����
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

//�ǵݹ�鲢����
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc false");
		return;
	}
	int left = 0, right = n - 1;
	int gap = 1;   //���Ϊ 1 �����������

	while (gap < n)
	{
		for (int j = 0; j < right; j += gap*2)
		{
			//[j, j+gap-1] [j+gap, j+gap*2-1]
			int begin1 = j, begin2 = j + gap, end1 = j + gap - 1, end2 = j + gap * 2 - 1;
			//���Ƕ������
			//1,ǰ�����βС��right �� ֻ��ǰ���䣬û��������
			if (end1 >= right)
				break;
			//2����ǰ���䣬��������С��right��
			if (end2 > right)
			{
				end2 = right;
			}

			_Merge(a, tmp, begin1, end1, begin2, end2);

		}

		gap *= 2;
	}

}

//��������
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
	//������ֵ����Сֵ�Ĳ���ӳ��
	gap = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * gap);
	memset(count, 0 ,sizeof(int) * gap);
	
	//��ǵ�count��
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	//��ֵ��ȥ
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
	// ��������
	//InsertSort(a, n);
	// ϣ������
	//ShellSort(a, n);
	// ѡ������
	//SelectSort(a, n);
	// ������
	//HeapSort(a, n);
	// ð������
	Bubble(a, n);
	// ����
	//QuickSort(a, 0, n - 1);
	//�ǵݹ����
	//QuickSortNonR(a, 0, n - 1);
	//�鲢����
	//MergeSort(a, n);
	//�ǵݹ�鲢
	//MergeSortNonR(a, n);
	//��������
	//CountSort(a, n);


	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	//TestOP();

	return 0;
}