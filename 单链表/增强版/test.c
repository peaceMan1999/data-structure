#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void Test1()
{
	SLTNode* plist = NULL;
	SLTPrint(plist);
	SLTPushFront(&plist, 1);
	SLTPrint(plist);
	SLTPushFront(&plist, 2);
	SLTPrint(plist);
	SLTPushFront(&plist, 3);
	SLTPrint(plist);
	SLTPushFront(&plist, 4);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPushBack(&plist, 5);
	SLTPrint(plist);
	SLTPushBack(&plist, 6);
	SLTPrint(plist);

}

void Test2()
{
	SLTNode* plist = NULL;
	SLTNode* pos = NULL;
	SLTPushFront(&plist, 3);
	SLTPrint(plist);

	pos = SLTFind(plist, 3);
	SLTInsert(pos, 30);
	SLTPrint(plist);
	SLTInsertAfter(&plist, pos, 10);
	SLTPrint(plist);
	pos = SLTFind(plist, 30);
	SLTInsertAfter(&plist, pos, 20);
	SLTPrint(plist);

}
 
void Test3()
{
	SLTNode* plist = NULL;
	SLTNode* pos = NULL;
	SLTPushFront(&plist, 3);
	SLTPrint(plist);
	pos = SLTFind(plist, 3);
	SLTInsert(pos, 30);
	SLTPrint(plist);
	pos = SLTFind(plist, 30);
	SListErase(&plist, pos);
	SLTPrint(plist);

}

void Test4()
{
	SLTNode* plist = NULL;
	SLTNode* pos = NULL;
	SLTPrint(plist);
	SLTPushFront(&plist, 1);
	SLTPrint(plist);
	SLTPushFront(&plist, 2);
	SLTPrint(plist);
	SLTPushFront(&plist, 3);
	SLTPrint(plist);
	SLTPushFront(&plist, 4);
	SLTPrint(plist);
	pos = SLTFind(plist, 4);
	SLTRevise(pos,100);
	//SListDestory(&plist);
	SLTPrint(plist);

}

int main()
{

	//Test1();
	//Test2();
	//Test3();
	Test4();

	return 0;
}
