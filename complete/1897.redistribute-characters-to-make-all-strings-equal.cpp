/*
 * @lc app=leetcode id=1897 lang=c
 *
 * [1897] Redistribute Characters to Make All Strings Equal
 */

// @lc code=start
class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        unordered_map<char, int> hash;
        for (auto s : words)
        {
            for (auto c : s)
                ++hash[c];
        }

        int n = words.size();
        for (auto i : hash)
        {
            if (i.second % n)
                return false;
        }
        return true;
    }
};
// @lc code=end

// Note: hash table