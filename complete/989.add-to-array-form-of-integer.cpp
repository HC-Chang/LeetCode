/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int N = num.size();
        int cur = k;
        vector<int> ans;

        int i = N;
        while (--i >= 0 || cur > 0)
        {
            if (i >= 0)
                cur += num[i];
            ans.push_back(cur % 10);
            cur /= 10;
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

// Official Solution