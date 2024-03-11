/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */

// @lc code=start
class Solution
{
public:
    string customSortString(string order, string s)
    {
        int hash[26] = {0};
        int l1 = order.size();
        int l2 = s.size();

        for (int i = 0; i < l2; i++)
            ++hash[s[i] - 'a'];

        string ans;
        for (int i = 0; i < l1; i++)
        {
            while (hash[order[i] - 'a']-- > 0)
                ans += order[i];
        }

        for (int i = 0; i < l2; i++)
        {
            if (hash[s[i] - 'a'] > 0)
                ans += s[i];
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table