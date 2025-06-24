/*
 * @lc app=leetcode id=2200 lang=cpp
 *
 * [2200] Find All K-Distant Indices in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == key)
            {
                for (int j = i - k; j <= i + k; j++)
                {
                    if (j < 0 || j >= n)
                        continue;
                    if (ans.empty() || j > ans.back())
                        ans.push_back(j);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

// Note: two pointers