/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

// @lc code=start
class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int len = s.size();
        unordered_map<char, int> hash;
        int max = -1;
        int diff;
        for (int i = 0; i < len; i++)
        {
            if (hash.find(s[i]) == hash.end())
                hash[s[i]] = i;
            else
            {
                diff = i - hash[s[i]] - 1;
                if (diff > max)
                    max = diff;
            }
        }
        return max;
    }
};
// @lc code=end

// Note: hash table