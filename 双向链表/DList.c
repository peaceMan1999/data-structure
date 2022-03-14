#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

//����
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

//��ʼ��
ListNode* ListInit(ValType x)
{
	ListNode* plist = ListBuy(0);
	plist->next = plist;
	plist->prev = plist;
	return plist;
}

//β��
void ListPushBack(ListNode* plist, ValType x)
{
	ListInsert(plist, x);
}

//ͷ��
void ListPushFront(ListNode* plist, ValType x)
{
	ListInsert(plist->prev, x);
}

//βɾ
void ListPopBack(ListNode* plist)
{
	ListErase(plist->prev);
}

//ͷɾ
void ListPopFront(ListNode* plist)
{
	ListErase(plist->next);
}

//����
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

//��ǰ��
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

//���ɾ
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* next = pos->next;
	ListNode* prev = pos->prev;
	free(pos);
	prev->next = next;
	next->prev = prev;
}

//��С
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

//�п�
void ListJudge(ListNode* plist)
{
	assert(plist);
	if (plist->next == plist)
		printf("��\n");
	else
		printf("�ǿ�\n");
}

//��ӡ
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

//���
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