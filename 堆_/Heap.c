#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void AdjustDown(heap* hp, int k, HpDataType parent)
{
	int child = parent * 2 + 1;

	while (child < k)
	{
		if (child < k - 1 && hp->a[child + 1] > hp->a[child])
		{
			child++;
		}
		if (hp->a[child] > hp->a[parent])
		{
			Swap(&hp->a[child], &hp->a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;

	}

}

void HeapInit(heap* hp, HpDataType* a, int k)
{
	assert(hp);

	HpDataType* pa = (HpDataType*)malloc(sizeof(HpDataType) * k + 1);
	if (pa == NULL)
	{
		perror("malloc false");
		exit(-1);
	}
	hp->a = pa;
	memcpy(hp->a, a, sizeof(HpDataType) * k);
	hp->capcity = k;
	hp->sz = k;

	//

	for (int i = (hp->sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp, hp->sz, i);
	}

}

void HeapDestroy(heap* hp)
{
	free(hp->a);
	hp->a = NULL;
	hp->capcity = hp->sz = 0;
}

void HeapPush(heap* hp, HpDataType x)
{
	assert(hp);
	if (hp->capcity == hp->sz)
	{
		hp->a = (HpDataType*)realloc(hp->a ,sizeof(HpDataType) * hp->capcity*2 );
		if (hp->a == NULL)
		{
			perror("realloc false");
			exit(-1);
		}
	}
	hp->a[hp->sz] = x;
	hp->sz++;
	for (int i = (hp->sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp, hp->sz, i);
	}

}

void HeapPop(heap* hp)
{
	assert(hp);
	assert(hp->sz);

	int ret = hp->a[0];
	hp->a[0] = hp->a[hp->sz - 1];
	hp->a[hp->sz - 1] = ret;
	hp->sz--;
	for (int i = (hp->sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp, hp->sz, i);
	}
}

HpDataType HeapTop(heap* hp)
{
	assert(hp);
	assert(hp->sz);

	return hp->a[0];
}

bool HeapEmpty(heap* hp)
{
	assert(hp);
	assert(hp->sz);

	return hp->sz == 0;
}

int HeapSize(heap* hp)
{
	assert(hp);
	assert(hp->sz);

	return hp->sz;
}

void HeapPrint(heap* hp)
{
	assert(hp);

	for (int i = 0; i < hp->sz; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");

	int i, j = 0;
	int count = 0;
	int k = 1;
	int n = 6;
	for (i = 0; i < n; i++)
	{
		if (count >= hp->sz)
			break;
		for (j = hp->sz-k; j > 0; j--)
		{
			printf(" ");
		}
		for (j = 0; j < k; j++)
		{
			printf(" %d ", hp->a[count]);
			count++;
			if (count >= hp->sz)
				break;
		}
		k *= 2;
		printf("\n\n");
	}

}

