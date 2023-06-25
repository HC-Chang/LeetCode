/*
 * @lc app=leetcode id=485 lang=c
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
// Solution 2:
int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int max_count = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
            ++count;
        else
        {
            if (count > max_count)
                max_count = count;
            count = 0;
        }
    }
    return max_count > count ? max_count : count;
}
// @lc code=end

// Solution 1:

// int findMaxConsecutiveOnes(int* nums, int numsSize){
//     int max_count = 0;
//     int count = 0;
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (nums[i] == 1)
//         {
//             ++count;
//             if (count > max_count)
//                 max_count = count;
//         }
//         else
//             count = 0;
//     }
//     return max_count;
// }
