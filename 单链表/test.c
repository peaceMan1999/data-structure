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

 
int main()
{

	Test1();

	return 0;
}


