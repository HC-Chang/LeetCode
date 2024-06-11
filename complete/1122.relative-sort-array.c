/*
 * @lc app=leetcode id=1122 lang=c
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size, int *returnSize)
{
    int hash[1001] = {0};
    for (int i = 0; i < arr1Size; i++)
        ++hash[arr1[i]];

    *returnSize = 0;
    for (int i = 0; i < arr2Size; i++)
    {
        if (hash[arr2[i]])
        {
            for (int j = 0; j < hash[arr2[i]]; j++)
                arr1[(*returnSize)++] = arr2[i];
            hash[arr2[i]] = 0;
            if (*returnSize == arr1Size)
                return arr1;
        }
    }

    for (int i = 0; i < 1001; i++)
    {
        if (hash[i])
        {
            for (int j = 0; j < hash[i]; j++)
                arr1[(*returnSize)++] = i;
            hash[i] = 0;
            if (*returnSize == arr1Size)
                return arr1;
        }
    }
    return arr1;
}
// @lc code=end

// Note: hash table