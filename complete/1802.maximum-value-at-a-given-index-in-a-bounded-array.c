/*
 * @lc app=leetcode id=1802 lang=c
 *
 * [1802] Maximum Value at a Given Index in a Bounded Array
 */

// @lc code=start
long count(long h, long n, long index)
{
    long sum = 0;
    if (h > index)
        sum += (h - index + h) * (index + 1) / 2;
    else
    {
        sum += (1 + h) * h / 2;
        sum += index + 1 - h;
    }
    if (h > n - index)
        sum += (h + h - (n - index) + 1) * (n - index) / 2;
    else
    {
        sum += (h + 1) * h / 2;
        sum += (n - (index + h));
    }
    return sum - h;
}

int maxValue(int n, int index, int maxSum)
{
    int left = 1;
    int right = maxSum;
    int mid;
    while (left < right)
    {
        mid = right - (right - left) / 2;
        if (count(mid, n, index) <= (long)maxSum)
            left = mid;
        else
            right = mid - 1;
    }
    return left;
}
// @lc code=end

// Note: Binary Search