/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
// Solution 2: pair + sorting

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return {};
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({arr[i], i});
        sort(v.begin(), v.end());

        vector<int> ans(n);
        ans[v[0].second] = 1;
        for (int i = 1; i < n; i++)
        {
            ans[v[i].second] = ans[v[i - 1].second];
            if (v[i].first > v[i - 1].first)
                ++ans[v[i].second];
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table + sorting

// Solution 1: hash table + sorting

// class Solution
// {
// public:
//     vector<int> arrayRankTransform(vector<int> &arr)
//     {
//         int n = arr.size();
//         if (n == 0)
//             return {};

//         unordered_map<int, int> hash;
//         for (auto a : arr)
//             ++hash[a];

//         vector<pair<int, int>> vec(hash.begin(), hash.end());
//         sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b)
//              { return b.first > a.first; });

//         int rank = 1;
//         for (auto v : vec)
//             hash[v.first] = rank++;

//         for (int i = 0; i < n; i++)
//             arr[i] = hash[arr[i]];

//         return arr;
//     }
// };