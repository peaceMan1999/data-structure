//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
//void Swap(int* pa, int* pc)
//{
//	int tmp = *pa;
//	*pa = *pc;
//	*pc = tmp;
//}
//
//void Heap(int a[], int sz, int parent)
//{
//	int child = parent * 2 + 1;
//	
//	while (child < sz)
//	{
//		if (child < sz - 1 && a[child + 1] > a[child])
//		{
//			child++;
//		}
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//	
//}
//
//int main()
//{
//	//int a[] = { 27,15,19,18,28,34,65,49,25,37 };
//	int a[] = { 15,18,28,34,27,19,49,25,37,65 };
//
//	int sz = sizeof(a) / sizeof(a[0]);
//	int parent = 0;
//
//	//Heap(a, sz, parent);
//	/*for (int i = (sz - 1 - 1) / 2; i >= 0; i--)
//	{
//		Heap(a, sz, i);
//	}*/
//	while (sz > 0)
//	{
//		for (int i = (sz - 1 - 1) / 2; i >= 0; i--)
//		{
//			Heap(a, sz, i);
//		}
//		int tmp = a[0];
//		a[0] = a[sz - 1];
//		a[sz - 1] = tmp;
//		sz--;
//	}
//	//RiseHeap(a, sz, parent);
//
//	return 0;
//}

