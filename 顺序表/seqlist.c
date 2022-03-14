#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"


//��ʼ���ṹ��
void SeqListInit(SeqList* pa)
{
	assert(pa);

	pa->data = NULL;
	pa->sz = pa->capacity = 0;
}

//�ͷſռ�
void SeqListDistory(SeqList* pa)
{
	assert(pa);

	free(pa->data);
	pa->data = NULL;
	pa->capacity = 0;
	pa->sz = 0;
}

//��̬����
void SeqListFounded(SeqList* pa)
{
	if (pa->sz == pa->capacity)
	{
		int new_capacity = pa->capacity == 0 ? 4 : pa->capacity * 2; //��Ŀ�����

		Seqdata* new_data = (Seqdata*)realloc(pa->data, new_capacity * sizeof(Seqdata));
		if (NULL == new_data)   //�жϿ�ָ��
		{
			perror("Founded");
			exit(-1);
		}

		pa->data = new_data;
		pa->capacity = new_capacity;
	}

}

//β��
void SeqListPushBack(SeqList* pa, Seqdata x)
{
	assert(pa);
	
	SeqListFounded(pa);

	pa->data[pa->sz] = x;
	pa->sz++;

}

//ͷ��
void SeqListPushFront(SeqList* pa, Seqdata x)
{
	assert(pa);

	SeqListFounded(pa);

	int ret = pa->sz - 1;  //��Ϊ���±�����Ҫ-1
	while (ret >= 0)
	{
		pa->data[ret + 1] = pa->data[ret];
		ret--;
	}
	pa->data[0] = x;
	pa->sz++;

}

//��ӡ˳���
void PrintSeqList(SeqList* pa)
{
	int i = 0;
	for (i = 0; i < pa->sz; i++)
	{
		printf("%d ", pa->data[i]);
	}

}

//βɾ
void SeqListPopBack(SeqList* pa)
{
	assert(pa);

	//ֱ��--sz�����ؼ��ɣ����ñ�Ϊ0��
	if (pa->sz != 0)
		pa->sz--;

}

//ͷɾ
void SeqListPopFront(SeqList* pa)
{
	assert(pa);

	int ret = 0;
	if (pa->sz != 0)  //û����ʱ��ɾ
	{
		while (ret < pa->sz - 1)  //�Ӻ���ǰ��
		{
			pa->data[ret] = pa->data[ret + 1];
			ret++;
		}
		pa->sz--;  //���ǵ����һ����
	}

}
