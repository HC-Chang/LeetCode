/*
 * @lc app=leetcode id=3011 lang=c
 *
 * [3011] Find if Array Can Be Sorted
 */

// @lc code=start
int count_bits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count += n & 1;
        n >>= 1;
    }

    return count;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool canSortArray(int *nums, int numsSize)
{
    int n = numsSize;

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] <= nums[i + 1])
            continue;
        else
        {
            if (count_bits(nums[i]) == count_bits(nums[i + 1]))
                swap(&nums[i], &nums[i + 1]);
            else
                return false;
        }
    }

    for (int i = n - 1; i >= 1; i--)
    {
        if (nums[i] >= nums[i - 1])
            continue;
        else
        {
            if (count_bits(nums[i]) == count_bits(nums[i - 1]))
                swap(&nums[i], &nums[i - 1]);
            else
                return false;
        }
    }

    return true;
}
// @lc code=end

// Note: bit manipulation