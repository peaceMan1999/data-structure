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

//��ӡ
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

//β��
void SLTPushBack(SLTNode** pplist, SLTDataType x)
{
	SLTNode* new = BuySLTNode(x);
	//1����
	//2���ǿ�
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

//ͷ��
void SLTPushFront(SLTNode** pplist, SLTDataType x)
{
	SLTNode* new = BuySLTNode(x);
	new->next = *pplist;
	*pplist = new;
}

//βɾ
void SLTPopBack(SLTNode** pplist)
{
	//1��0���ڵ�
	if (*pplist == NULL)
		return;
	//2��1���ڵ�
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//3������ڵ�
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

//ͷɾ
void SLTPopFront(SLTNode** pplist)
{
	//1��
	if (*pplist == NULL)
		return;
	//2��
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//3��
	else
	{
		SLTNode* end = (*pplist)->next;
		SLTNode* front = *pplist;
		free(front);
		*pplist = end;
	}


}
