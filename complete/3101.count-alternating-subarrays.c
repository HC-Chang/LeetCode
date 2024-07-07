/*
 * @lc app=leetcode id=3101 lang=c
 *
 * [3101] Count Alternating Subarrays
 */

// @lc code=start
// Solution 2:

long long countAlternatingSubarrays(int *nums, int numsSize)
{
    long long cnt = 1;
    int tmp_cnt = 1;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
            tmp_cnt = 0;
        tmp_cnt++;
        cnt += tmp_cnt;
    }

    return cnt;
}
// @lc code=end

// Note: math

// Solution 1:

// long long countAlternatingSubarrays(int *nums, int numsSize)
// {
//     long long cnt = 0;
//     long long start = 0;
//     for (int i = 1; i < numsSize; i++)
//     {
//         if (nums[i] == nums[i - 1])
//         {
//             cnt += (i - start + 1) * (i - start) / 2;
//             start = i;
//         }
//     }

//     if (start < numsSize)
//         cnt += (numsSize - start + 1) * (numsSize - start) / 2;

//     return cnt;
// }
