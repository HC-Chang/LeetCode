/*
 * @lc app=leetcode id=2364 lang=cpp
 *
 * [2364] Count Number of Bad Pairs
 */

// @lc code=start
class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> hash;
        long long bad_pairs = 0;
        int diff;

        for (int i = 0; i < n; i++)
        {
            diff = i - nums[i];
            bad_pairs += i - hash[diff];
            ++hash[diff];
        }

        return bad_pairs;
    }
};

// @lc code=end

// Note: hash table + math

// Official Solution