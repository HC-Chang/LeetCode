/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
// Solution 2:
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(n);
        int idx = 0;
        arr[idx++] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > arr[idx - 1])
                arr[idx++] = nums[i];
            else
            {
                for (int j = 0; j < idx; j++)
                {
                    if (arr[j] >= nums[i])
                    {
                        arr[j] = nums[i];
                        break;
                    }
                }
            }
        }

        return idx;
    }
};
// @lc code=end

// Note: DP / greedy + B-Search

// Solution 1:
// class Solution
// {
// public:
//     int lengthOfLIS(vector<int> &nums)
//     {
//         int dp_max = 1;
//         int n = nums.size();
//         vector<int> dp(n);
//         for (int i = 0; i < n; i++)
//         {
//             dp[i] = 1;
//             for (int j = 0; j < i; j++)
//             {
//                 if (nums[i] > nums[j])
//                     dp[i] = max(dp[i], dp[j] + 1);
//             }
//             if (dp[i] > dp_max)
//                 dp_max = dp[i];
//         }

//         return dp_max;
//     }
// };