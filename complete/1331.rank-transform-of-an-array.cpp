/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return {};

        unordered_map<int, int> hash;
        for (auto a : arr)
            ++hash[a];

        vector<pair<int, int>> vec(hash.begin(), hash.end());
        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b)
             { return b.first > a.first; });

        int rank = 1;
        for (auto v : vec)
            hash[v.first] = rank++;

        for (int i = 0; i < n; i++)
            arr[i] = hash[arr[i]];

        return arr;
    }
};
// @lc code=end

// Note: hash table + sorting