#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

void test()
{
	SeqList s;    //定义结构体
	SeqListInit(&s);  //初始化结构体

	//尾插
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	//头插
	SeqListPushFront(&s, 5);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 3);
	//尾删
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	//头删
	SeqListPopFront(&s);
	SeqListPopFront(&s);

	PrintSeqList(&s);

	SeqListDistory(&s);  //释放空间
	
}


int main()
{
	test();

	return 0;
}

