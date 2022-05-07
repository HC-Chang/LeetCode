/*
 * @lc app=leetcode id=707 lang=c
 *
 * [707] Design Linked List
 */

// @lc code=start

typedef struct NODE
{
    int val;
    struct NODE *next;
} MyLinkedList;

// NOTE tail, size
int myLinkedListSize;
// MyLinkedList *tail;

MyLinkedList *myLinkedListCreate()
{
    myLinkedListSize = 0;
    MyLinkedList *p = calloc(1, sizeof(MyLinkedList));

    return p;
}

// void myLinkedListPrint(MyLinkedList *obj)
// {
//     MyLinkedList *p = obj;
//     while (p->next)
//     {
//         printf("%i\r\n", p->val);
//         p = p->next;
//     }
//     printf("%i\r\n", p->val);
//     printf("---\r\n");
// }

int myLinkedListGet(MyLinkedList *obj, int index)
{
    // myLinkedListPrint(obj);

    if (index < 0 || index >= myLinkedListSize)
    {
        return -1;
    }

    if (index == 0)
    {
        return obj->val;
    }

    MyLinkedList *p = obj;
    for (int i = 0; i < index; i++)
    {
        if (!p->next)
        {
            p->next = calloc(1, sizeof(MyLinkedList));
        }
        p = p->next;
    }

    return p->val;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    // myLinkedListPrint(obj);

    if (myLinkedListSize == 0)
    {
        obj->val = val;
        myLinkedListSize++;

        return;
    }

    MyLinkedList *p = calloc(1, sizeof(MyLinkedList));
    p->val = obj->val;
    p->next = obj->next;
    obj->val = val;
    obj->next = p;

    myLinkedListSize++;

    // myLinkedListPrint(obj);
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    // myLinkedListPrint(obj);
    if (myLinkedListSize == 0)
    {
        obj->val = val;
        myLinkedListSize++;

        return;
    }

    MyLinkedList *p = calloc(1, sizeof(MyLinkedList));
    p->val = val;

    MyLinkedList *temp = obj;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = p;

    myLinkedListSize++;
    // myLinkedListPrint(obj);
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    // myLinkedListPrint(obj);
    if (index < 0 || index > myLinkedListSize)
    {
        return;
    }

    if (index == 0)
    {
        if (myLinkedListSize == 0)
        {
            obj->val = val;
            myLinkedListSize++;
            return;
        }

        MyLinkedList *p = calloc(1, sizeof(MyLinkedList));
        p->val = obj->val;
        p->next = obj->next;
        obj->val = val;
        obj->next = p;
        myLinkedListSize++;
        return;
    }

    MyLinkedList *temp = obj;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }

    MyLinkedList *p = calloc(1, sizeof(MyLinkedList));
    p->val = val;
    p->next = temp->next;

    temp->next = p;

    myLinkedListSize++;
    // myLinkedListPrint(obj);
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    // myLinkedListPrint(obj);
    if (index < 0 || index >= myLinkedListSize)
    {
        return;
    }

    if (myLinkedListSize == 0)
    {
        return;
    }

    if (index == 0)
    {
        if (myLinkedListSize == 1)
        {

            obj->val = 0;
            myLinkedListSize--;
            return;
        }
        obj->val = obj->next->val;
        obj->next = obj->next->next;
        myLinkedListSize--;
        return;
    }

    MyLinkedList *temp = obj;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;

    myLinkedListSize--;
    // myLinkedListPrint(obj);
}

// NOTE all linkedlist
void myLinkedListFree(MyLinkedList *obj)
{
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
// @lc code=end

// NOTE
// index 邊界檢查
// index == 0 || index == size -> 儲存值
