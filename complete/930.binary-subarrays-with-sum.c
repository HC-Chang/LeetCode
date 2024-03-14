/*
 * @lc app=leetcode id=930 lang=c
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
int numSubarraysWithSum(int *nums, int numsSize, int goal)
{
    int hash[30000] = {0};
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];

        if (sum == goal)
            cnt++;
        if ((sum - goal >= 0) && hash[(sum - goal)])
            cnt += hash[(sum - goal)];

        hash[sum]++;
    }

    return cnt;
}
// @lc code=end

// Note: hash table / sliding window

// Solutioin 1: sliding window

// Official Solution

// int numSubarraysWithSum(int *nums, int numsSize, int goal)
// {
//     int left1 = 0, left2 = 0, right = 0;
//     int sum1 = 0, sum2 = 0;
//     int ret = 0;
//     while (right < numsSize)
//     {
//         sum1 += nums[right];
//         while (left1 <= right && sum1 > goal)
//         {
//             sum1 -= nums[left1];
//             left1++;
//         }
//         sum2 += nums[right];
//         while (left2 <= right && sum2 >= goal)
//         {
//             sum2 -= nums[left2];
//             left2++;
//         }
//         ret += left2 - left1;
//         right++;
//     }
//     return ret;
// }