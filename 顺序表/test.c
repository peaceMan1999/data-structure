#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

void test()
{
	SeqList s;    //����ṹ��
	SeqListInit(&s);  //��ʼ���ṹ��

	//β��
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	//ͷ��
	SeqListPushFront(&s, 5);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 3);
	//βɾ
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	//ͷɾ
	SeqListPopFront(&s);
	SeqListPopFront(&s);

	PrintSeqList(&s);

	SeqListDistory(&s);  //�ͷſռ�
	
}


int main()
{
	test();

	return 0;
}

