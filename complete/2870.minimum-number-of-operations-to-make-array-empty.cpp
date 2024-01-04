/*
 * @lc app=leetcode id=2870 lang=cpp
 *
 * [2870] Minimum Number of Operations to Make Array Empty
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            ++hash[nums[i]];
        int op = 0;
        int tmp;
        for (auto h : hash)
        {
            if (h.second == 1)
                return -1;
            else
            {
                op += h.second / 3;
                if (h.second % 3 != 0)
                    op++;
            }
        }
        return op;
    }
};
// @lc code=end

// Note: hash table