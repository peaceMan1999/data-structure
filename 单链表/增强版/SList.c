#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//malloc�ռ�
static SLTNode* BuySLTNode(SLTDateType x)
{
	SLTNode* new = (SLTNode*)malloc(sizeof(SLTNode));
	if (new == NULL)
		return;
	new->date = x;
	new->next = NULL;

	return new;
}

//��ӡ
void SLTPrint(SLTNode* plist)
{
	SLTNode* end = plist;
	while (end != NULL)
	{
		printf("%d", end->date);
		end = end->next;
		printf("->");
	}
	printf("NULL\n");
}

//β��
void SLTPushBack(SLTNode** pplist, SLTDateType x)
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
void SLTPushFront(SLTNode** pplist, SLTDateType x)
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
	//3��
	else
	{
		SLTNode* end = (*pplist)->next;
		free(*pplist);
		*pplist = end;
	}

}

//���ҽڵ�
SLTNode* SLTFind(SLTNode* plist, SLTDateType x)
{
	SLTNode* find = plist;

	while (find != NULL)
	{
		//1
		if (find->date == x)
		{
			return find;
		}
		find = find->next;
	}
	printf("û���ҵ�\n");
	return NULL;
}

//��
void SLTRevise(SLTNode* pos, SLTDateType x)
{
	assert(pos);
	pos->date = x;
	return;
}

//�ҵ�����
void SLTInsert(SLTNode* pos, SLTDateType x)
{
	assert(pos);

	SLTNode* new = BuySLTNode(x);
	new->next = pos->next;
	pos->next = new;
}

//posǰһ����
void SLTInsertAfter(SLTNode** pplist, SLTNode* pos, SLTDateType x)
{
	assert(pos);
	SLTNode* new = BuySLTNode(x);
	SLTNode* front = NULL;
	SLTNode* end = *pplist;

	if (end == pos)
	{
		new->next = pos;
		*pplist = new;
	}
	else
	{
		while (end != pos)
		{
			front = end;
			end = end->next;
		}
		new->next = front->next;
		front->next =new;
	}

}

//pos�󡤼�
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
		return;
	else
	{
		SLTNode* end = pos->next;
		pos->next = end->next;
		free(end);
		end = NULL;
	}

}

//posλɾ��
void SListErase(SLTNode** pplist, SLTNode* pos)
{
	assert(pos);

	if (*pplist == pos)
	{
		SLTNode* end = pos->next;
		*pplist = end;
		free(pos);
		pos = NULL;
	}
	else
	{
		SLTNode* front = *pplist;
		while (front->next != pos)
		{
			front = front->next;
		}
		front->next = pos->next;
		free(pos);
		pos = NULL;
	}

}

//����ɾ
void SListDestory(SLTNode** pplist)
{
	assert(*pplist);
	
	while ((*pplist)->next != NULL)
	{
		SLTNode* end = (*pplist)->next;
		free(*pplist);
		*pplist = end;
	}
	free(*pplist);
	*pplist = NULL;
}
