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


//Í·²åÎ²²å
void SLTPushBack(SLTNode** pplist, SLTDataType x);
void SLTPushFront(SLTNode** pplist, SLTDataType x);

//Í·É¾Î²É¾
void SLTPopBack(SLTNode** pplist);
void SLTPopFront(SLTNode** pplist);

//´òÓ¡
void SLTPrint(SLTNode* plist);
