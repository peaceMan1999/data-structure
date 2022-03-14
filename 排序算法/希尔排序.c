//#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//
//int* bubble(int* nums, int sz)
//{
//    for (int i = 0; i < sz; i++)
//    {
//        int k = 0;
//        for (int j = 0; j < sz - i - 1; j++)
//        {
//            if (nums[j] > nums[j + 1])
//            {
//                int tmp = nums[j];
//                nums[j] = nums[j + 1];
//                nums[j + 1] = tmp;
//                k = 1;
//            }
//        }
//        if (k == 0)
//        {
//            break;
//        }
//    }
//    return nums;
//}
//
//int single(int* nums, int sz)
//{
//    int* next = nums + 1;
//    int* prev = nums;
//    int sum = 0;
//    int count = 1;
//    int i = 0;
//
//    while (i < sz - 1)
//    {
//        if (*next == *prev)
//        {
//            count = 0;
//        }
//        else if (*next != *prev)
//        {
//            if (count != 0)
//                sum += *prev;
//            count = 1;
//        }
//        prev = next;
//        next++;
//        i++;
//    }
//    if (count != 0)
//        sum += *prev;
//    return sum;
//}
//
//int sumOfUnique(int* nums, int numsSize) {
//    if (numsSize < 2)
//        return nums[0];
//    int* new = bubble(nums, numsSize);
//    int ret = single(new, numsSize);
//
//    return ret;
//}
//
//int main()
//{
//    int arr[] = { 1, 2, 3, 2 };
//    int sz = 4;
//
//    printf("%d ", sumOfUnique(arr, 4));
//
//    return 0;
//}

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

	}

}

int main()
{

	//int a[] = { 4,5,3 };
	int a[] = { 10,9,8,7,6,5,4,3,2,1,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10 };

	int n = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, n);
	ShellSort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}