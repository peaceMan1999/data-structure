#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int HpDataType;

struct Heap
{
	HpDataType* a;
	int sz;
	int capcity;
};

typedef struct Heap heap;

void HeapInit(heap* hp, HpDataType* a, int k);

void HeapDestroy(heap* hp);

void HeapPush(heap* hp, HpDataType x);

void HeapPop(heap* hp);

HpDataType HeapTop(heap* hp);

bool HeapEmpty(heap* hp);

int HeapSize(heap* hp);

void HeapPrint(heap* hp);

