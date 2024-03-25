/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int hash[nums.size() + 1];
        memset(hash, 0, sizeof(hash));
        vector<int> res;
        for (auto i : nums)
        {
            if (++hash[i] == 2)
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

// Note: hash table