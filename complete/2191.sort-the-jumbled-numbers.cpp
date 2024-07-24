/*
 * @lc app=leetcode id=2191 lang=cpp
 *
 * [2191] Sort the Jumbled Numbers
 */

// @lc code=start
class Solution
{
public:
    int convert(int val, vector<int> &mapping)
    {
        if (val == 0)
            return mapping[0];
        int ans = 0;
        int offset = 1;
        while (val)
        {
            ans += mapping[val % 10] * offset;
            offset *= 10;
            val /= 10;
        }
        return ans;
    }

    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        int n = nums.size();

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
            vec.emplace_back(i, convert(nums[i], mapping));

        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b)
             { return a.second < b.second; });

        vector<int> ans;
        for (auto v : vec)
            ans.push_back(nums[v.first]);
        return ans;
    }
};
// @lc code=end

// Note: sorting