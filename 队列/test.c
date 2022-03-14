#define _CRT_SECURE_NO_WARNINGS 1

#include "QList.h"

void Test1()
{
	Queue que;
	QueueInit(&que);

	QueuePush(&que, 1);
	QueuePush(&que, 2);
	QueuePush(&que, 3);
	QueuePush(&que, 4);
	QueueSize(&que);

	while (!QueueEmpty(&que))
	{
		printf("%d ", QueueFront(&que));
		QueuePop(&que);
	}
	QueueDestroy(&que);

}

int main()
{
	Test1();

	return 0;
}