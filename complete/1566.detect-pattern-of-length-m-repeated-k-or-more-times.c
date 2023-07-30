/*
 * @lc app=leetcode id=1566 lang=c
 *
 * [1566] Detect Pattern of Length M Repeated K or More Times
 */

// @lc code=start
bool containsPattern(int *arr, int arrSize, int m, int k)
{
    int tmp_index;
    for (int i = 0; i < arrSize - m; i++)
    {
        tmp_index = i;
        while ((tmp_index < arrSize - m) && (arr[tmp_index] == arr[tmp_index + m]))
            tmp_index++;
        if (((tmp_index - i) / m) + 1 >= k)
            return true;
    }
    return false;
}
// @lc code=end
