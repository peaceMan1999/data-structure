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

extern void SLTPushBack(SLTNode** pplist, SLTDateType x);		//β��
extern void SLTPushFront(SLTNode** pplist, SLTDateType x);		//ͷ��
extern void SLTPopBack(SLTNode** pplist);						//βɾ
extern void SLTPopFront(SLTNode** pplist);						//ͷɾ
extern SLTNode* SLTFind(SLTNode* plist, SLTDateType x);			//��
extern void SLTRevise(SLTNode* pos, SLTDateType x);					//��
extern void SLTPrint(SLTNode* plist);							//��ӡ
extern void SLTInsertAfter(SLTNode** pplist, SLTNode* pos, SLTDateType x);//�ҵ�ǰ����
extern void SLTInsert(SLTNode* pos, SLTDateType x);				//�ҵ�����
extern void SListDestory(SLTNode** pplist);						//����ɾ��
extern void SListEraseAfter(SLTNode* pos);						//pos��һ��ɾ��
extern void SListErase(SLTNode** pplist, SLTNode* pos);			//posɾ��