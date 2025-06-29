/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start
class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int MOD = 1e9 + 7;
        int n = nums.size();
        int pow[n];
        pow[0] = 1;
        for (int i = 1; i < n; i++)
            pow[i] = pow[i - 1] * 2 % MOD;
        int count = 0;

        for (int i = 0, j = n - 1; i < n; i++)
        {
            while (nums[i] + nums[j] > target && j >= i && j > 0)
                j--;
            if (nums[i] + nums[j] <= target && j >= i && j > 0)
                count = (count + pow[j - i]) % MOD;
        }
        return count;
    }
};
// @lc code=end

// Note: two pointers + binary search + sorting