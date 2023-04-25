/*
 * @lc app=leetcode id=2336 lang=c
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
typedef struct
{
    int *arr;
    int index;
} SmallestInfiniteSet;

SmallestInfiniteSet *smallestInfiniteSetCreate()
{
    SmallestInfiniteSet *obj = malloc(sizeof(SmallestInfiniteSet));
    obj->arr = malloc(1001 * sizeof(int));
    for (int i = 1; i < 1001; i++)
        obj->arr[i] = 1;
    obj->index = 1;
    return obj;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet *obj)
{
    int r = obj->index;
    obj->arr[obj->index]--;
    while (obj->index < 1001 && !obj->arr[obj->index])
        obj->index++;
    return r;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet *obj, int num)
{
    if (num < obj->index)
        obj->index = num;
    obj->arr[num] = 1;
}

void smallestInfiniteSetFree(SmallestInfiniteSet *obj)
{
    free(obj->arr);
    free(obj);
}
// @lc code=end
