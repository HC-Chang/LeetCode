/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> hash1;
        unordered_map<int, int> hash2;
        for (auto &i : arr)
            ++hash1[i];
        for (auto i : hash1)
        {
            if (hash2[i.second])
                return false;
            ++hash2[i.second];
        }
        return true;
    }
};
// @lc code=end

// Note: hash map