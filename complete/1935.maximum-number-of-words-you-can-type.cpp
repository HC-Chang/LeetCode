/*
 * @lc app=leetcode id=1935 lang=cpp
 *
 * [1935] Maximum Number of Words You Can Type
 */

// @lc code=start
class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        set<int> s;
        for (auto &c : brokenLetters)
            s.insert(c);
        int cnt = 0;
        bool can_type = true;
        for (auto &c : text)
        {
            if (c == ' ')
            {
                if (can_type)
                    cnt++;
                can_type = true;
            }
            if (s.find(c) != s.end())
                can_type = false;
        }
        if (can_type)
            cnt++;
        return cnt;
    }
};
// @lc code=end

// Note: hash table
