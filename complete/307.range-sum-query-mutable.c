/*
 * @lc app=leetcode id=307 lang=c
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
typedef struct
{
    int *tree;
    int size;
} NumArray;

void update(NumArray *obj, int i, int val)
{
    i++;
    while (i <= obj->size)
    {
        obj->tree[i] += val;
        i += i & (-i);
    }
}
int sum(NumArray *obj, int i)
{
    i++;
    int sum = 0;
    while (i > 0)
    {
        sum += obj->tree[i];
        i -= i & (-i);
    }
    return sum;
}

NumArray *numArrayCreate(int *nums, int numsSize)
{
    NumArray *obj = (NumArray *)malloc(sizeof(NumArray));
    obj->size = numsSize;
    obj->tree = (int *)calloc(numsSize + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++)
        update(obj, i, nums[i]);
    return obj;
}

void numArrayUpdate(NumArray *obj, int index, int val)
{
    update(obj, index, val - sum(obj, index) + sum(obj, index - 1));
}

int numArraySumRange(NumArray *obj, int left, int right)
{
    return sum(obj, right) - sum(obj, left - 1);
}

void numArrayFree(NumArray *obj)
{
    free(obj->tree);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, index, val);

 * int param_2 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/
// @lc code=end

// Segment Tree