#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"


//初始化结构体
void SeqListInit(SeqList* pa)
{
	assert(pa);

	pa->data = NULL;
	pa->sz = pa->capacity = 0;
}

//释放空间
void SeqListDistory(SeqList* pa)
{
	assert(pa);

	free(pa->data);
	pa->data = NULL;
	pa->capacity = 0;
	pa->sz = 0;
}

//动态扩容
void SeqListFounded(SeqList* pa)
{
	if (pa->sz == pa->capacity)
	{
		int new_capacity = pa->capacity == 0 ? 4 : pa->capacity * 2; //三目运算符

		Seqdata* new_data = (Seqdata*)realloc(pa->data, new_capacity * sizeof(Seqdata));
		if (NULL == new_data)   //判断空指针
		{
			perror("Founded");
			exit(-1);
		}

		pa->data = new_data;
		pa->capacity = new_capacity;
	}

}

//尾插
void SeqListPushBack(SeqList* pa, Seqdata x)
{
	assert(pa);
	
	SeqListFounded(pa);

	pa->data[pa->sz] = x;
	pa->sz++;

}

//头插
void SeqListPushFront(SeqList* pa, Seqdata x)
{
	assert(pa);

	SeqListFounded(pa);

	int ret = pa->sz - 1;  //因为是下标所以要-1
	while (ret >= 0)
	{
		pa->data[ret + 1] = pa->data[ret];
		ret--;
	}
	pa->data[0] = x;
	pa->sz++;

}

//打印顺序表
void PrintSeqList(SeqList* pa)
{
	int i = 0;
	for (i = 0; i < pa->sz; i++)
	{
		printf("%d ", pa->data[i]);
	}

}

//尾删
void SeqListPopBack(SeqList* pa)
{
	assert(pa);

	//直接--sz，隐藏即可，不用变为0；
	if (pa->sz != 0)
		pa->sz--;

}

//头删
void SeqListPopFront(SeqList* pa)
{
	assert(pa);

	int ret = 0;
	if (pa->sz != 0)  //没有数时不删
	{
		while (ret < pa->sz - 1)  //从后往前移
		{
			pa->data[ret] = pa->data[ret + 1];
			ret++;
		}
		pa->sz--;  //覆盖掉最后一个数
	}

}
