/*
 * @lc app=leetcode id=1287 lang=c
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */

// @lc code=start
int findSpecialInteger(int *arr, int arrSize)
{
    int cnt = 1;
    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            cnt++;
            if (cnt > arrSize / 4)
                return arr[i];
        }
        else
            cnt = 1;
    }
    return arr[arrSize - 1];
}
// @lc code=end
