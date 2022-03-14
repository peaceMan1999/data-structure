#define _CRT_SECURE_NO_WARNINGS 1

/*
* 1
21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    struct ListNode* newhead = NULL;
    struct ListNode* tail = NULL;
    if (list1->val > list2->val)
    {
        newhead = list2;
        tail = list2;
        list2 = list2->next;
    }
    else if (list1->val <= list2->val)
    {
        newhead = list1;
        tail = list1;
        list1 = list1->next;
    }
    while (list1 && list2)
    {
        if (list1->val > list2->val)
        {
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }
        else if (list1->val <= list2->val)
        {
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
        }
    }
    if (list1 == NULL)
        tail->next = list2;
    else
        tail->next = list1;
    return newhead;
}
    */

/*
* 2
输入一个链表，输出该链表中倒数第k个结点。

输入：
1, { 1,2,3,4,5 }

返回值：
{ 5 }

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    struct ListNode* fast = pListHead;
    struct ListNode* slow = pListHead;
    if (pListHead == NULL)
        return NULL;
    while (k--)
    {
        fast = fast->next;
        if (fast == NULL && k > 0)
            return NULL;
    }
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
*/

/*
* 3
206. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* end = head;
    struct ListNode* newhead = NULL;
    while (end)
    {
        struct ListNode* next = end->next;
        end->next = newhead;
        newhead = end;
        end = next;
    }
    return newhead;
}
*/


/*
* 4
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }
    return slow;
}
*/


/*
* 5
203. 移除链表元素
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* mid = head;
    struct ListNode* end = NULL;
    struct ListNode* front = NULL;
    if (head == NULL)
        return head;
    while(mid)
    {
        struct ListNode*end = mid->next;
        if(mid->val == val)
        {
            if (front == NULL)
            {
                free(mid);
                head = end;
                mid = end;
            }
            else
            {
                front->next = mid->next;
                free(mid);
                mid = NULL;
                if (end != NULL)
                mid = end;
            }
        }
        else
        {
            front = mid;
            mid = mid->next;
        }

    }
    return head;
}
*/

//6
/*
* CM11 链表分割
* 
* 现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
/*
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode* run = pHead;
        if (run == NULL)
            return NULL;
        ListNode* lesshead = (ListNode*)malloc(sizeof(ListNode*));
        ListNode* greaterhead = (ListNode*)malloc(sizeof(ListNode*));
        ListNode* lesstail = lesshead;
        ListNode* greatertail = greaterhead;
        if (run->val >= x)
        {
            greaterhead->next = run;
            greatertail = run;
            run = run->next;
        }
        else if (run->val < x)
        {
            lesshead->next = run;
            lesstail = run;
            run = run->next;
        }

        while (run)
        {
            if (run->val >= x)
            {
                greatertail->next = run;
                greatertail = run;
                run = run->next;
            }
            else if (run->val < x)
            {
                lesstail->next = run;
                lesstail = run;
                run = run->next;
            }
        }
        greatertail->next = run;
        lesstail->next = greaterhead->next;
        ListNode* greaternext = greaterhead->next;
        lesstail->next = greaternext;
        free(greaterhead);
        greaterhead = NULL;
        ListNode* lessnext = lesshead->next;
        free(lesshead);
        lesshead = NULL;
        return lessnext;
    }
};
*/


//7
//对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
/*
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        if (A == NULL)
            return NULL;
        else if (A->next == NULL)
            return true;
        ListNode* fast = A;
        ListNode* slow = A;
        while (fast && fast->next)
        {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* point = slow;
        ListNode* newhead = NULL;
        ListNode* next = slow->next;
        while (next != fast)
        {
            slow->next = newhead;
            newhead = slow;
            slow = next;
            next = next->next;
        }
        slow->next = newhead;
        ListNode* cur = A;
        while (cur != point && slow != NULL)
        {
            if (cur->val != slow->val)
            {
                return NULL;
            }
            cur = cur->next;
            slow = slow->next;
        }
        return true;
    }
};
*/


/*
* 8、相交链表
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (headB == NULL || headA == NULL)
        return NULL;
    struct ListNode* tailA = headA;
    struct ListNode* tailB = headB;
    int countA = 0;
    int countB = 0;
    while (tailA->next)
    {
        countA++;
        tailA = tailA->next;
    }
    while (tailB->next)
    {
        countB++;
        tailB = tailB->next;
    }
    if (tailA != tailB)
        return NULL;
    int k = 0;
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    if (countA > countB)
    {
        k = countA - countB;
        while (k--)
            curA = curA->next;
    }
    else if (countA <= countB)
    {
        k = countB - countA;
        while (k--)
            curB = curB->next;
    }
    while (curA)
    {
        if ((curA) == (curB))
            return curA;
        curA = curA->next;
        curB = curB->next;
    }
    return NULL;

}

*/