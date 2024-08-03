/*
 * @lc app=leetcode id=1460 lang=c
 *
 * [1460] Make Two Arrays Equal by Reversing Subarrays
 */

// @lc code=start
bool canBeEqual(int *target, int targetSize, int *arr, int arrSize)
{
    int hash[1001] = {0};
    for (int i = 0; i < arrSize; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 0; i < targetSize; i++)
    {
        if (hash[target[i]] == 0)
            return false;

        hash[target[i]]--;
    }
    for (int i = 0; i < 1001; i++)
    {
        if (hash[i] > 0)
            return false;
    }

    return true;
}
// @lc code=end

// Note: hash table