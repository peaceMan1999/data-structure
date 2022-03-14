#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//malloc空间
static SLTNode* BuySLTNode(SLTDateType x)
{
	SLTNode* new = (SLTNode*)malloc(sizeof(SLTNode));
	if (new == NULL)
		return;
	new->date = x;
	new->next = NULL;

	return new;
}

//打印
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

//尾插
void SLTPushBack(SLTNode** pplist, SLTDateType x)
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
void SLTPushFront(SLTNode** pplist, SLTDateType x)
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
	//3个
	else
	{
		SLTNode* end = (*pplist)->next;
		free(*pplist);
		*pplist = end;
	}

}

//查找节点
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
	printf("没有找到\n");
	return NULL;
}

//改
void SLTRevise(SLTNode* pos, SLTDateType x)
{
	assert(pos);
	pos->date = x;
	return;
}

//找到插入
void SLTInsert(SLTNode* pos, SLTDateType x)
{
	assert(pos);

	SLTNode* new = BuySLTNode(x);
	new->next = pos->next;
	pos->next = new;
}

//pos前一个加
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

//pos后·减
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

//pos位删除
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

//整个删
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
