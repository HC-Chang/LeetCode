/*
 * @lc app=leetcode id=769 lang=c
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
int maxChunksToSorted(int *arr, int arrSize)
{
    int chunks = 0, max_val = 0;

    for (int i = 0; i < arrSize; i++)
    {
        max_val = fmax(max_val, arr[i]);
        if (max_val == i)
            chunks++;
    }

    return chunks;
}
// @lc code=end

// Note: stack

// Official Solution