/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

// @lc code=start
int minPartitions(char *n)
{
    int size = strlen(n);
    for (int i = 0; i < size; i++)
    {
        if (n[i] > n[0])
            n[0] = n[i];
    }
    return n[0] - '0';
}
// @lc code=end

// Note: greedy