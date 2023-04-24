/*
 * @lc app=leetcode id=735 lang=c
 *
 * [735] Asteroid Collision
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void push_arr(int val, int *index, int *arr)
{
    arr[(*index)++] = val;
}
void pop_arr(int *index, int *arr)
{
    arr[--(*index)] = 0;
}
int *asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize)
{
    int *arr = calloc(asteroidsSize, sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < asteroidsSize; i++)
    {
        if (*returnSize == 0 || arr[*returnSize - 1] < 0 || asteroids[i] > 0)
            push_arr(asteroids[i], returnSize, arr);
        else
        {
            while (*returnSize && arr[*returnSize - 1] > 0 && arr[*returnSize - 1] < -asteroids[i])
                pop_arr(returnSize, arr);
            if (*returnSize && arr[*returnSize - 1] == -asteroids[i])
                pop_arr(returnSize, arr);
            else if (*returnSize == 0 || arr[*returnSize - 1] < 0)
                push_arr(asteroids[i], returnSize, arr);
        }
    }
    arr = realloc(arr, *returnSize * sizeof(int));
    return arr;
}
// @lc code=end
