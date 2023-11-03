/*
 * @lc app=leetcode id=1441 lang=cpp
 *
 * [1441] Build an Array With Stack Operations
 */

// @lc code=start
class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        int cur = 0;
        int nn = target.size();
        vector<string> ans;
        for (int i = 0; i < nn; i++)
        {
            while (++cur < target[i])
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            ans.push_back("Push");
        }

        return ans;
    }
};
// @lc code=end

// Note: stack