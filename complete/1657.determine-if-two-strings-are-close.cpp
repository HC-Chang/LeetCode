/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        int len1 = word1.size();
        int len2 = word2.size();
        if (len1 != len2)
            return false;
        vector<int> map1(26);
        vector<int> map2(26);

        for (int i = 0; i < len1; i++)
        {
            ++map1[word1[i] - 'a'];
            ++map2[word2[i] - 'a'];
        }
        for (int i = 0; i < 26; i++)
        {
            if ((map1[i] == 0 && map2[i] != 0) || (map1[i] != 0 && map2[i] == 0))
                return false;
        }
        sort(map1.begin(), map1.end(), greater<int>());
        sort(map2.begin(), map2.end(), greater<int>());

        for (int i = 0; i < 26; i++)
        {
            if (map1[i] != map2[i])
                return false;
            if (map1[i] == 0)
                break;
        }
        return true;
    }
};
// @lc code=end

// Note: hash map + sort