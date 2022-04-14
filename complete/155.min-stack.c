/*
 * @lc app=leetcode id=155 lang=c
 *
 * [155] Min Stack
 */

// @lc code=start

typedef struct
{
    int *vals;
    int *mins;
    int size;

} MinStack;

MinStack *minStackCreate()
{
    MinStack *create = calloc(1, sizeof(MinStack));

    return create;
}

void minStackPush(MinStack *obj, int val)
{
    obj->vals = realloc(obj->vals, sizeof(int) * (obj->size + 1));
    obj->vals[obj->size] = val;

    obj->mins = realloc(obj->mins, sizeof(int) * (obj->size + 1));
    if (obj->size == 0 || obj->mins[obj->size - 1] > val)
    {
        obj->mins[obj->size] = val;
    }
    else
    {
        obj->mins[obj->size] = obj->mins[obj->size - 1];
    }
    obj->size++;
}

void minStackPop(MinStack *obj)
{
    obj->size--;
}

int minStackTop(MinStack *obj)
{
    return obj->vals[obj->size - 1];
}

// NOTE pop 可能會將原紀錄之最小值釋放，因此使用陣列紀錄
int minStackGetMin(MinStack *obj)
{
    return obj->mins[obj->size - 1];
}

void minStackFree(MinStack *obj)
{
    free(obj->vals);
    free(obj->mins);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
// @lc code=end
