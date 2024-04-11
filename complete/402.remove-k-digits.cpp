/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        int keep = n - k;
        string ans;
        for (char c : num)
        {
            while (k && ans.size() && ans.back() > c)
            {
                ans.pop_back();
                --k;
            }
            if (ans.size() || c != '0')
                ans.push_back(c);
        }
        while (ans.size() && k--)
            ans.pop_back();
        return ans.empty() ? "0" : ans;
    }
};
// @lc code=end

// Note: stack