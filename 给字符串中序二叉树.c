#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
描述
编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 
例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。
建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

输入描述：
输入包括1行字符串，长度不超过100。
输出描述：
可能有多组测试数据，对于每组数据， 输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。 每个输出结果占一行。
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