/*
 * @lc app=leetcode id=3741 lang=cpp
 *
 * [3741] Minimum Distance Between Three Equal Elements II
 */

// @lc code=start
class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        unordered_map<int, vector<int>> hash;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            hash[nums[i]].push_back(i);
        int m = INT_MAX;
        for (auto &h : hash)
        {
            if (h.second.size() >= 3)
            {
                for (int i = 0; i < h.second.size() - 2; i++)
                {
                    int tmp = abs(h.second[i] - h.second[i + 1]) + abs(h.second[i + 1] - h.second[i + 2]) + abs(h.second[i + 2] - h.second[i]);
                    if (tmp < m)
                        m = tmp;
                }
            }
        }

        if (m == INT_MAX)
            return -1;
        return m;
    }
};
// @lc code=end

// Note: hash table