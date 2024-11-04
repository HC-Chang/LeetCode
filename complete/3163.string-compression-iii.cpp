/*
 * @lc app=leetcode id=3163 lang=cpp
 *
 * [3163] String Compression III
 */

// @lc code=start
class Solution
{
public:
    string compressedString(string word)
    {
        int n = word.size();
        char c = word[0];
        int cnt = 1;
        string ans;
        for (int i = 1; i < n; i++)
        {
            if (word[i] == c)
                cnt++;
            else
            {
                while (cnt > 9)
                {
                    ans += "9";
                    ans += c;
                    cnt -= 9;
                }
                ans += to_string(cnt) + c;
                c = word[i];
                cnt = 1;
            }
        }
        while (cnt > 9)
        {
            ans += "9";
            ans += c;
            cnt -= 9;
        }
        ans += to_string(cnt) + c;
        return ans;
    }
};
// @lc code=end
