#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

//创建
ListNode* ListBuy(ValType x)
{
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	if (new == NULL)
	{
		perror("Buy");
		return NULL;
	}
	new->next = NULL;
	new->prev = NULL;
	new->val = x;
	return new;
}

//初始化
ListNode* ListInit(ValType x)
{
	ListNode* plist = ListBuy(0);
	plist->next = plist;
	plist->prev = plist;
	return plist;
}

//尾插
void ListPushBack(ListNode* plist, ValType x)
{
	ListInsert(plist, x);
}

//头插
void ListPushFront(ListNode* plist, ValType x)
{
	ListInsert(plist->prev, x);
}

//尾删
void ListPopBack(ListNode* plist)
{
	ListErase(plist->prev);
}

//头删
void ListPopFront(ListNode* plist)
{
	ListErase(plist->next);
}

//查找
ListNode* ListFind(ListNode* plist, ValType x)
{
	assert(plist->next);
	ListNode* cur = plist->next;
	while (cur != plist)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//点前加
void ListInsert(ListNode*pos, ValType x)
{
	assert(pos);
	ListNode* new = ListBuy(x);
	if (new == NULL)
		return NULL;
	ListNode* prev = pos->prev;
	new->next = pos;
	new->prev = prev;
	pos->prev = new;
	prev->next = new;
}

//点后删
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* next = pos->next;
	ListNode* prev = pos->prev;
	free(pos);
	prev->next = next;
	next->prev = prev;
}

//大小
void ListSize(ListNode* plist)
{
	assert(plist);
	ListNode* cur = plist->next;
	int count = 0;
	while (cur != plist)
	{
		count++;
		cur = cur->next;
	}
	printf("%d\n", count);
}

//判空
void ListJudge(ListNode* plist)
{
	assert(plist);
	if (plist->next == plist)
		printf("空\n");
	else
		printf("非空\n");
}

//打印
void ListPrint(ListNode* plist)
{
	assert(plist);
	ListNode* cur = plist->next;
	while (cur != plist)
	{
		printf("%d->", cur->val); 
		cur = cur->next;
	}
	printf("NULL\n");
}

//清空
ListNode* ListDistory(ListNode* plist)
{
	assert(plist);
	ListNode* cur = plist->next;
	while (cur != plist)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
		next = next->next;
	}
	free(plist);
	plist = NULL;
	return plist;
}