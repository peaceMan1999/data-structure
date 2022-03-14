#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void Test1()
{
	stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	StackDistroy(&st);
}


int main()
{
	Test1();

	return 0;
}