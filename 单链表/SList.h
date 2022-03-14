#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int SLTDataType;

typedef struct SLTNode
{
	SLTDataType data;
	struct SLTNode* next;
}SLTNode;


//ͷ��β��
void SLTPushBack(SLTNode** pplist, SLTDataType x);
void SLTPushFront(SLTNode** pplist, SLTDataType x);

//ͷɾβɾ
void SLTPopBack(SLTNode** pplist);
void SLTPopFront(SLTNode** pplist);

//��ӡ
void SLTPrint(SLTNode* plist);
