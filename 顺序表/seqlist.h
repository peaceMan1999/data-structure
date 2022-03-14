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

//头插尾插
void SeqListPushBack(SeqList* pa, Seqdata x);
void SeqListPushFront(SeqList* pa, Seqdata x);

//头删尾删
void SeqListPopBack(SeqList* pa);
void SeqListPopFront(SeqList* pa);

//创建、初始化、销毁空间
void SeqListFounded(SeqList* pa);
void SeqListInit(SeqList* pa);
void SeqListDistory(SeqList* pa);

//打印
void PrintSeqList(SeqList* pa);