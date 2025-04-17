/*
 * @lc app=leetcode id=2176 lang=cpp
 *
 * [2176] Count Equal and Divisible Pairs in an Array
 */

// @lc code=start
class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        unordered_map<int, vector<int>> hash;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            hash[nums[i]].push_back(i);
        if (hash.size() == n)
            return 0;
        int cnt = 0;
        for (auto h : hash)
        {
            int nn = h.second.size();
            if (nn == 1)
                continue;
            for (int i = 0; i < nn; i++)
            {
                for (int j = i + 1; j < nn; j++)
                {
                    if (h.second[i] * h.second[j] % k == 0)
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

// Note: array