/*
 * @lc app=leetcode id=3354 lang=c
 *
 * [3354] Make Array Elements Equal to Zero
 */

// @lc code=start
int countValidSelections(int *nums, int numsSize)
{

    int l_arr[numsSize];
    int r_arr[numsSize];
    l_arr[0] = nums[0];
    r_arr[numsSize - 1] = nums[numsSize - 1];
    int idx[numsSize];
    int ii = 0;
    if (nums[0] == 0)
        idx[ii++] = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == 0)
            idx[ii++] = i;
        l_arr[i] = l_arr[i - 1] + nums[i];
        r_arr[numsSize - 1 - i] = r_arr[numsSize - i] + nums[numsSize - 1 - i];
    }

    int cnt = 0;
    int val;
    for (int i = 0; i < ii; i++)
    {
        val = abs(l_arr[idx[i]] - r_arr[idx[i]]);
        if (val <= 1)
        {
            if (val == 1)
                cnt++;
            else
                cnt += 2;
        }
    }
    return cnt;
}
// @lc code=end

// Note: prefix sum + simulation