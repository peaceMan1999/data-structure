#define _CRT_SECURE_NO_WARNINGS 1

#include "QList.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef char BTDataType;

typedef struct BinaryTree
{
	struct BinaryTree* left;
	struct BinaryTree* right;
	BTDataType data;
}BTNode;

//��ʼ��
BTNode* BTCreate(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc false");
		exit(-1);
	}
	BTNode* root = node;
	root->left = NULL;
	root->right = NULL;
	root->data = x;

	return root;
}

//ǰ��
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);

}

//����
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PrevOrder(root->left);
	printf("%c ", root->data);
	PrevOrder(root->right);

}

//����
void PoseOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PrevOrder(root->left);
	PrevOrder(root->right);
	printf("%c ", root->data);

}

//1�����Ľ��
//void TreeSize(BTNode* root, int* sz)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	(*sz)++;
//	TreeSize(root->left, sz);
//	TreeSize(root->right, sz);
//
//}

//2�����Ľ��
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//���������м������
int TreeLfRt(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + TreeLfRt(root->right) + TreeLfRt(root->left);
}

//���Ĳ���
int TreeLayer(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = TreeLayer(root->left);
	int right = TreeLayer(root->right);

	return left > right ? left + 1 : right + 1;
}

//ÿ���м������
int TreeLayerNode(BTNode* root, int k, int count)
{
	if (k == 1)
	{
		return 1;
	}
	while (count > k - 1)
	{
		if (root->left == NULL && root->right == NULL)
		{
			return 0;
		}
		else if (root->left != NULL && root->right != NULL)
		{
			return 2;
		}
		else if (root->left != NULL || root->right != NULL)
		{
			return 1;
		}

	}
	count += 1;
	return TreeLayerNode(root->left, k - 1, count) + TreeLayerNode(root->right, k - 1, count);
}

//���м���Ҷ��
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//������
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;

	BTNode* leftret = TreeFind(root->left, x);
	if (leftret)
	{
		return leftret;
	}
	BTNode* rightret = TreeFind(root->right, x);
	{
		return rightret;
	}

	return NULL;
}

//������
void TreeDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
}

//����������
void BinaryTreeLevelOrder(BTNode* root)
{
	
}

void test1(BTNode* root)
{

	BinaryTreeLevelOrder(root);

}

int main()
{
	BTNode* A = BTCreate('A');
	BTNode* B = BTCreate('B');
	BTNode* C = BTCreate('C');
	BTNode* D = BTCreate('D');
	BTNode* E = BTCreate('E');
	BTNode* F = BTCreate('F');
	BTNode* G = BTCreate('G');
	BTNode* Q = BTCreate('Q');

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = Q;
	C->left = E;
	C->right = F;
	F->right = G;

	test1(A);

	TreeDestroy(A);
	A = NULL;

	return 0;
}