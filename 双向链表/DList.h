#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

typedef int ValType;
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	ValType val;
}ListNode;

//创建
ListNode* ListBuy(ValType x);
//初始化
ListNode* ListInit(ValType x);
//尾插
void ListPushBack(ListNode* plist, ValType x);
//头插
void ListPushFront(ListNode* plist, ValType x);
//尾删
void ListPopBack(ListNode* plist);
//头删
void ListPopFront(ListNode* plist);
//查找
ListNode* ListFind(ListNode* plist, ValType x);
//点前加
void ListInsert(ListNode* pos, ValType x);
//点后删
void ListErase(ListNode* pos);
//大小
void ListSize(ListNode* plist);
//判空
void ListJudge(ListNode* plist);
//清空
ListNode* ListDistory(ListNode* plist);
//打印
void ListPrint(ListNode* plist);
