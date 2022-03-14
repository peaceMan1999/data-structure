#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;

typedef struct SLTNode
{
	SLTDateType date;
	struct SLTNode* next;
}SLTNode;

extern void SLTPushBack(SLTNode** pplist, SLTDateType x);		//尾插
extern void SLTPushFront(SLTNode** pplist, SLTDateType x);		//头插
extern void SLTPopBack(SLTNode** pplist);						//尾删
extern void SLTPopFront(SLTNode** pplist);						//头删
extern SLTNode* SLTFind(SLTNode* plist, SLTDateType x);			//查
extern void SLTRevise(SLTNode* pos, SLTDateType x);					//改
extern void SLTPrint(SLTNode* plist);							//打印
extern void SLTInsertAfter(SLTNode** pplist, SLTNode* pos, SLTDateType x);//找到前插入
extern void SLTInsert(SLTNode* pos, SLTDateType x);				//找到插入
extern void SListDestory(SLTNode** pplist);						//链表删除
extern void SListEraseAfter(SLTNode* pos);						//pos后一个删除
extern void SListErase(SLTNode** pplist, SLTNode* pos);			//pos删除