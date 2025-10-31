/*
 * @lc app=leetcode id=3289 lang=cpp
 *
 * [3289] The Two Sneaky Numbers of Digitville
 */

// @lc code=start
class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        vector<int> ans;
        for (auto &n : nums)
        {
            if (hash[n]++ == 1)
                ans.push_back(n);
        }

        return ans;
    }
};
// @lc code=end

// Note: hash table