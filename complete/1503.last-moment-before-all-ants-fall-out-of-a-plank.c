/*
 * @lc app=leetcode id=1503 lang=c
 *
 * [1503] Last Moment Before All Ants Fall Out of a Plank
 */

// @lc code=start
int getLastMoment(int n, int *left, int leftSize, int *right, int rightSize)
{
    int max_time = 0;
    for (int i = 0; i < leftSize; i++)
        if (left[i] > max_time)
            max_time = left[i];
    for (int i = 0; i < rightSize; i++)
        if (n - right[i] > max_time)
            max_time = n - right[i];
    return max_time;
}
// @lc code=end
