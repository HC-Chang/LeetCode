/*
 * @lc app=leetcode id=1146 lang=c
 *
 * [1146] Snapshot Array
 */

// @lc code=start

struct DATA
{
    struct DATA *next;
    struct DATA *prev;
    int sid;
    int val;
};

#define DATA struct DATA

typedef struct
{
    int length;
    int maxSid;
    DATA data[];
} SnapshotArray;

SnapshotArray *snapshotArrayCreate(int length)
{
    SnapshotArray *obj = malloc(sizeof(SnapshotArray) + sizeof(DATA) * length);
    memset(obj, 0, sizeof(SnapshotArray) + sizeof(DATA) * length);
    obj->maxSid = 0;
    obj->length = length;
    return obj;
}

void snapshotArraySet(SnapshotArray *obj, int index, int val)
{
    DATA *head = &obj->data[index];
    if (!head->prev)
    {
        DATA *d = malloc(sizeof(DATA));
        d->val = 0;
        d->sid = 0;
        d->prev = head;
        d->next = head;
        head->prev = d;
        head->next = d;
    }

    if (head->prev->sid != obj->maxSid)
    {
        DATA *tail = head->prev;
        DATA *d = malloc(sizeof(DATA));
        d->sid = obj->maxSid;
        d->val = val;
        d->next = head;
        d->prev = tail;

        tail->next = d;
        head->prev = d;
    }
    else
        head->prev->val = val;
}

int snapshotArraySnap(SnapshotArray *obj)
{
    return obj->maxSid++;
}

int snapshotArrayGet(SnapshotArray *obj, int index, int snap_id)
{
    DATA *head = &obj->data[index];
    while (head->next != &obj->data[index] && head->next != NULL)
    {
        DATA *t = head->next;
        if (t->sid == snap_id)
        {
            return t->val;
        }
        else if (t->sid > snap_id)
            return head->val;

        head = head->next;
    }
    return head->val;
}

void snapshotArrayFree(SnapshotArray *obj)
{
    for (int i = 0; i < obj->length; i++)
    {
        DATA *d = obj->data[i].next;
        while (d != &obj->data[i] && d != NULL)
        {
            DATA *next = d->next;
            free(d);
            d = next;
        }
    }
    free(obj);
}

/**
 * Your SnapshotArray struct will be instantiated and called as such:
 * SnapshotArray* obj = snapshotArrayCreate(length);
 * snapshotArraySet(obj, index, val);

 * int param_2 = snapshotArraySnap(obj);

 * int param_3 = snapshotArrayGet(obj, index, snap_id);

 * snapshotArrayFree(obj);
*/
// @lc code=end

// Note: Double Linked List
