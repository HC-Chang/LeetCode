/*
 * @lc app=leetcode id=3152 lang=cpp
 *
 * [3152] Special Array II
 */

// @lc code=start
class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums,
                                vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> arr(n);
        int end = 0;

        for (int start = 0; start < n; start++)
        {
            end = max(end, start);
            while (end < n - 1 && nums[end] % 2 != nums[end + 1] % 2)
                ++end;

            arr[start] = end;
        }

        vector<bool> ans(queries.size());

        for (int i = 0; i < queries.size(); i++)
        {
            vector<int> query = queries[i];
            int start = query[0];
            int end = query[1];

            ans[i] = end <= arr[start];
        }

        return ans;
    }
};
// @lc code=end

// Note: prefix sum

// Official Solution