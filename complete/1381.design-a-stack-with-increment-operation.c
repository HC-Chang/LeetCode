/*
 * @lc app=leetcode id=1381 lang=c
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
typedef struct
{
    int capacity;
    int idx;
    int *arr;
} CustomStack;

CustomStack *customStackCreate(int maxSize)
{
    CustomStack *obj = malloc(sizeof(CustomStack));
    obj->capacity = maxSize;
    obj->idx = 0;
    obj->arr = malloc(obj->capacity * sizeof(int));
    return obj;
}

void customStackPush(CustomStack *obj, int x)
{
    if (obj->idx >= obj->capacity)
        return;
    obj->arr[obj->idx++] = x;
}

int customStackPop(CustomStack *obj)
{
    if (obj->idx <= 0)
        return -1;
    return obj->arr[--obj->idx];
}

void customStackIncrement(CustomStack *obj, int k, int val)
{
    int cnt = fmin(k, obj->idx);
    for (int i = 0; i < cnt; i++)
        obj->arr[i] += val;
}

void customStackFree(CustomStack *obj)
{
    free(obj->arr);
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);

 * int param_2 = customStackPop(obj);

 * customStackIncrement(obj, k, val);

 * customStackFree(obj);
*/
// @lc code=end

// Note: stack + design