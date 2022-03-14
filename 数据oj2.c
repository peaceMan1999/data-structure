#define _CRT_SECURE_NO_WARNINGS 1


//1、复制带随机指针的链表
/*
* Definition for a Node.
* struct Node {
    *int val;
    *struct Node* next;
    *struct Node* random;
    *
};


struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;
    struct Node* cur = head;
    //1、单个拷贝链表，链接起来
    while (cur)
    {
        struct Node* next = cur->next;
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        cur->next = copy;
        copy->next = next;
        cur = next;
    }
    //2、把random链接起来
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
            copy->random = NULL;
        else
            copy->random = cur->random->next;
        cur = copy->next;
    }
    //3、断开节点
    struct Node* newhead, * newtail;
    newhead = newtail = (struct Node*)malloc(sizeof(struct Node));
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        newtail->next = copy;
        newtail = copy;
        cur->next = next;
        cur = next;
    }
    struct Node* guard = newhead;
    newhead = newhead->next;
    free(guard);
    guard = NULL;
    return newhead;
}
*/


//2、给定一个链表，判断链表中是否有环
/*
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    return false;
}
*/


//3、给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
/*
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
            {
                struct ListNode *meet = fast;
                while (meet != head)
                {
                    head = head->next;
                    meet = meet->next;
                }
                return meet;
            }

        }
    return NULL;
}
*/




