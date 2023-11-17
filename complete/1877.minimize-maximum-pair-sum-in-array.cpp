/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

// @lc code=start
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        nums[0] += nums[n - 1];
        for (int i = 1; i < n / 2; i++)
        {
            nums[i] += nums[n - 1 - i];
            if (nums[i] > nums[0])
                nums[0] = nums[i];
        }

        return nums[0];
    }
};

// @lc code=end
