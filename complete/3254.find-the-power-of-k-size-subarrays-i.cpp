/*
 * @lc app=leetcode id=3254 lang=cpp
 *
 * [3254] Find the Power of K-Size Subarrays I
 */

// @lc code=start
class Solution
{
public:
    int check(int i, vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int j = 1; j < k; j++)
        {
            if (i + j >= n || nums[i + j] - nums[i + j - 1] != 1)
                return -1;
        }
        return nums[i + k - 1];
    }

    vector<int> resultsArray(vector<int> &nums, int k)
    {
        if (k == 1)
            return nums;

        vector<int> ans;
        int n = nums.size();
        ans.push_back(check(0, nums, k));
        int tmp;
        for (int i = 1; i + k - 1 < n; i++)
        {
            tmp = check(i, nums, k);
            if (ans[i - 1] == -1)
                ans.push_back(tmp);
            else if (tmp - ans[i - 1] == 1)
                ans.push_back(tmp);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};
// @lc code=end

// Note: sliding window