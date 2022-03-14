#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

void Teat1()
{
	ListNode* plist = ListInit(0);
	ListPushBack(plist, 1);
	ListPushFront(plist, 2);
	ListNode* pos = ListFind(plist, 1);
	ListInsert(pos->prev, 3);

	//ListPopBack(plist);
	//ListPopFront(plist);

	ListJudge(plist);
	ListSize(plist);
	ListPrint(plist);	
	//plist = ListDistory(plist);

	//ListPrint(plist);
}

int main()
{
	Teat1();

	return 0;
}