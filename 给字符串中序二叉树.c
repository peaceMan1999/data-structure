#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
����
��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� 
�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������
������˶������Ժ��ٶԶ������������������������������

����������
�������1���ַ��������Ȳ�����100��
���������
�����ж���������ݣ�����ÿ�����ݣ� ����������ַ���������������������������У�ÿ���ַ����涼��һ���ո� ÿ��������ռһ�С�
*/

typedef struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    char val;
}TreeNode;

TreeNode* CreateTree(char* arr, int* pi)
{
    if (arr[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }

    TreeNode* new = (TreeNode*)malloc(sizeof(TreeNode));

    new->val = arr[*pi];
    (*pi)++;

    new->left = CreateTree(arr, pi);
    new->right = CreateTree(arr, pi);

    return new;
}

void ReadTree(TreeNode* tree)
{
    if (tree == NULL)
        return;

    ReadTree(tree->left);
    printf("%c ", tree->val);
    ReadTree(tree->right);
}

int main()
{
    char arr[100] = { 0 };
    scanf("%s", arr);

    int i = 0;
    TreeNode* tree = CreateTree(arr, &i);

    ReadTree(tree);

    return 0;
}