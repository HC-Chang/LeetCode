/*
 * @lc app=leetcode id=1346 lang=c
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
bool checkIfExist(int *arr, int arrSize)
{
    int i, j;
    for (i = 0; i < arrSize; i++)
    {
        for (j = i + 1; j < arrSize; j++)
        {
            if (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i])
                return true;
        }
    }

    return false;
}
// @lc code=end

// Note: hash table + sorting / two pointers