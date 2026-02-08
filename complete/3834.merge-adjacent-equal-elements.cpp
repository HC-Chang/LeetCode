/*
 * @lc app=leetcode id=3834 lang=cpp
 *
 * [3834] Merge Adjacent Equal Elements
 */

// @lc code=start
class Solution
{
public:
    vector<long long> mergeAdjacent(vector<int> &nums)
    {
        vector<long long> v;
        for (auto n : nums)
        {
            v.push_back(n);
            while (v.size() > 1 && v.rbegin()[0] == v.rbegin()[1])
            {
                v.pop_back();
                v.back() *= 2;
            }
        }
        return v;
    }
};
// @lc code=end
