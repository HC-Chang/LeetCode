/*
 * @lc app=leetcode id=624 lang=c
 *
 * [624] Maximum Distance in Arrays
 */

// @lc code=start
int maxDistance(int **arrays, int arraysSize, int *arraysColSize)
{
    int min = arrays[0][0];
    int max = arrays[0][arraysColSize[0] - 1];
    int res = INT_MIN;
    for (int i = 1; i < arraysSize; i++)
    {
        res = fmax(res, abs(arrays[i][0] - max));
        res = fmax(
            res, abs(arrays[i][arraysColSize[i] - 1] - min));
        max = fmax(max, arrays[i][arraysColSize[i] - 1]);
        min = fmin(min, arrays[i][0]);
    }
    return res;
}
// @lc code=end

// Note: greedy