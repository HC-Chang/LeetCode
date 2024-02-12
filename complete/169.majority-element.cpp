/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        int max_cnt = 0;
        int max_val = nums[0];
        for (auto i : nums)
        {
            if (++hash[i] > max_cnt)
            {
                max_cnt = hash[i];
                max_val = i;
                if (max_cnt > nums.size() / 2 + 1)
                    return i;
            }
        }
        return max_val;
    }
};
// @lc code=end

// Note: hash table