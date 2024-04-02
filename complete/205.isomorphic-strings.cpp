/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int map1[128] = {0};
        int map2[128] = {0};
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (map1[s[i]] != map2[t[i]])
                return false;
            map1[s[i]] = i + 1;
            map2[t[i]] = i + 1;
        }
        return true;
    }
};
// @lc code=end

// map size = 128 (ASCII Code)

// Note: hash table