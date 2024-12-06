/*
 * @lc app=leetcode id=2554 lang=c
 *
 * [2554] Maximum Number of Integers to Choose From a Range I
 */

// @lc code=start
int maxCount(int *banned, int bannedSize, int n, int maxSum)
{
    int hash[10001] = {0};
    for (int i = 0; i < bannedSize; i++)
        ++hash[banned[i]];
    int sum = 0;
    int cnt = 0;
    int boundary = fmin(maxSum, n);
    for (int i = 1; i <= boundary && sum + i <= maxSum; i++)
    {
        if (hash[i] > 0)
            continue;
        sum += i;
        cnt++;
    }
    return cnt;
}
// @lc code=end

// Note: hash table + greedy