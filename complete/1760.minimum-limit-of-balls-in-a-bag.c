/*
 * @lc app=leetcode id=1760 lang=c
 *
 * [1760] Minimum Limit of Balls in a Bag
 */

// @lc code=start
bool is_pass(int maxBallsInBag, int *nums, int numsSize, int maxOperations)
{
    int sum_op = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int operations = ceil(nums[i] / (double)maxBallsInBag) - 1;
        sum_op += operations;

        if (sum_op > maxOperations)
            return false;
    }
    return true;
}

int minimumSize(int *nums, int numsSize, int maxOperations)
{
    int left = 1;
    int right = 0;

    for (int i = 0; i < numsSize; i++)
        right = fmax(right, nums[i]);

    while (left < right)
    {
        int middle = (left + right) / 2;

        if (is_pass(middle, nums, numsSize, maxOperations))
            right = middle;
        else
            left = middle + 1;
    }
    return left;
}
// @lc code=end
