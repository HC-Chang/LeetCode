/*
 * @lc app=leetcode id=525 lang=c
 *
 * [525] Contiguous Array
 */

// @lc code=start

// 計算 0 與 1 的相差個數
void count(int range, int *nums, int *r)
{
    r[0] = 0;
    for (int i = 0; i < range; i++)
    {
        if (nums[i] == 0)
        {
            r[i + 1] = r[i] + 1;
        }
        else
        {
            r[i + 1] = r[i] - 1;
        }
    }
}

int findMaxLength(int *nums, int numsSize)
{
    int *r = calloc(numsSize + 1, sizeof(int));
    count(numsSize, nums, r);

    int *max_j_arr = calloc(numsSize * 2 + 1, sizeof(int));
    for (int i = 0; i < numsSize * 2 + 1; i++)
    {
        max_j_arr[i] = -1;
    }

    for (int i = 0; i < numsSize + 1; i++)
    {
        max_j_arr[r[i] + numsSize] = i;
    }

    int max_L = 0;
    int target;
    int max_j;
    int temp_length;
    for (int i = 1; i < numsSize; i++)
    {
        target = r[i - 1];
        max_j = max_j_arr[target + numsSize];

        temp_length = max_j - i + 1;
        if (max_L < temp_length)
        {
            max_L = temp_length;
        }
    }

    return max_L;
}
// @lc code=end

// NOTE
// count(i, j, nums) == count(0, j, nums) - count(0, i-1, nums)
// -> count(0, j, nums) == count(0, i-1, nums)
// 機率累積圖