#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* new = (SLTNode*)malloc(sizeof(SLTNode));
	if (new == NULL)
		return;
	new->data = x;
	new->next = NULL;

	return new;
}

//打印
void SLTPrint(SLTNode* plist)
{
	SLTNode* end = plist;
	while (end != NULL)
	{
		printf("%d", end->data);
		end = end->next;
		printf("->");
	}
	printf("NULL\n");
}

//尾插
void SLTPushBack(SLTNode** pplist, SLTDataType x)
{
	SLTNode* new = BuySLTNode(x);
	//1、空
	//2、非空
	if (*pplist == NULL)
	{
		*pplist = new;
	}
	else
	{
		SLTNode* end = *pplist;
		while (end->next != NULL)
		{
			end = end->next;
		}
		end->next = new;
	}
}

//头插
void SLTPushFront(SLTNode** pplist, SLTDataType x)
{
	SLTNode* new = BuySLTNode(x);
	new->next = *pplist;
	*pplist = new;
}

//尾删
void SLTPopBack(SLTNode** pplist)
{
	//1、0个节点
	if (*pplist == NULL)
		return;
	//2、1个节点
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//3、多个节点
	else
	{
		SLTNode* end = *pplist;
		SLTNode* front = NULL;
		while (end->next != NULL)
		{
			front = end;
			end = end->next;
		}
		free(end);
		end = NULL;
		front->next = NULL;
	}

}

//头删
void SLTPopFront(SLTNode** pplist)
{
	//1个
	if (*pplist == NULL)
		return;
	//2个
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//3个
	else
	{
		SLTNode* end = (*pplist)->next;
		SLTNode* front = *pplist;
		free(front);
		*pplist = end;
	}


}
