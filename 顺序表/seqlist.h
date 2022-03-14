#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef int Seqdata;

typedef struct SeqList
{
	Seqdata* data;
	int sz;
	int capacity;
}SeqList;

//ͷ��β��
void SeqListPushBack(SeqList* pa, Seqdata x);
void SeqListPushFront(SeqList* pa, Seqdata x);

//ͷɾβɾ
void SeqListPopBack(SeqList* pa);
void SeqListPopFront(SeqList* pa);

//��������ʼ�������ٿռ�
void SeqListFounded(SeqList* pa);
void SeqListInit(SeqList* pa);
void SeqListDistory(SeqList* pa);

//��ӡ
void PrintSeqList(SeqList* pa);