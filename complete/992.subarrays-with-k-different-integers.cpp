/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
class Solution
{
public:
    int helper(vector<int> &nums, int k)
    {
        int res = 0, left = 0;
        int n = nums.size();
        vector<int> hash(n + 1);

        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (++hash[nums[i]] == 1)
                ++cnt;
            while (cnt > k)
            {
                if (--hash[nums[left]] == 0)
                    --cnt;
                ++left;
            }
            res += i - left + 1;
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return helper(nums, k) - helper(nums, k - 1);
    }
};

// @lc code=end

// Note: hash table + sliding window