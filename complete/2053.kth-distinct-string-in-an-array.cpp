/*
 * @lc app=leetcode id=2053 lang=cpp
 *
 * [2053] Kth Distinct String in an Array
 */

// @lc code=start
class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> hash;
        for (auto &a : arr)
            ++hash[a];

        for (auto &a : arr)
        {
            if (hash[a] == 1)
                k--;
            if (k == 0)
                return a;
        }
        return "";
    }
};
// @lc code=end

// Note: hash table + counting