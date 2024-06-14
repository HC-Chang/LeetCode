/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
// Solution 2:

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int last = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= last)
            {
                cnt += last - nums[i] + 1;
                last++;
            }
            else
                last = nums[i];
        }
        return cnt;
    }
};
// @lc code=end

// Note: sorting + counting

// Solution 1:

// #define SIZE 101001
// class Solution
// {
// public:
//     int minIncrementForUnique(vector<int> &nums)
//     {
//         int hash[SIZE] = {0};
//         int cnt = 0;
//         int offset = 1;
//         int n = nums.size();
//         for (int i = 0; i < n; i++)
//         {
//             if (!hash[nums[i]])
//                 ++hash[nums[i]];
//             else
//             {
//                 while (nums[i] + offset < SIZE - 1 &&
//                        (hash[nums[i] + offset]) > 0)
//                     offset++;
//                 hash[nums[i] + offset] = 1;
//                 cnt += offset;
//                 offset = 1;
//             }
//         }

//         return cnt;
//     }
// };