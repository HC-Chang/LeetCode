/*
 * @lc app=leetcode id=1481 lang=cpp
 *
 * [1481] Least Number of Unique Integers after K Removals
 */

// @lc code=start
class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> hash;
        for (auto i : arr)
            ++hash[i];
        vector<pair<int, int>> vec(hash.begin(), hash.end());
        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b)
             { return b.second > a.second; });

        int n = vec.size();
        int i = 0;
        for (i = 0; i < n; i++)
        {
            if (k <= vec[i].second)
                break;
            k -= vec[i].second;
        }
        if (k == vec[i].second)
            i++;

        return n - i;
    }
};
// @lc code=end

// Note: hash table + sorting + counting