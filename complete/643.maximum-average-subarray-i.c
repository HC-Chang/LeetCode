/*
 * @lc app=leetcode id=643 lang=c
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
double findMaxAverage(int *nums, int numsSize, int k)
{
    int left = 0, right = 1;
    int count = 1;
    int tmp = nums[0];
    int max = INT_MIN;
    while (right < numsSize)
    {
        if (count < k)
        {
            tmp += nums[right++];
            count++;
            continue;
        }
        if (tmp > max)
            max = tmp;
        count--;
        tmp -= nums[left++];
    }
    if (tmp > max)
        max = tmp;
    return (double)max / k;
}
// @lc code=end

// Note: Sliding Window