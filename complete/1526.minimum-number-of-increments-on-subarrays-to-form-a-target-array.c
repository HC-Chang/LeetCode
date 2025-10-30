/*
 * @lc app=leetcode id=1526 lang=c
 *
 * [1526] Minimum Number of Increments on Subarrays to Form a Target Array
 */

// @lc code=start
int minNumberOperations(int *target, int targetSize)
{
    int ans = target[0];
    for (int i = 1; i < targetSize; ++i)
        ans += fmax(target[i] - target[i - 1], 0);
    return ans;
}
// @lc code=end

// Note: DP + stack + greedy + monotonic stack

// Official Solution