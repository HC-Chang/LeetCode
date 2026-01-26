/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int min_val = INT_MAX;
        vector<vector<int>> ans;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] < min_val)
            {
                ans.clear();
                min_val = arr[i] - arr[i - 1];
                ans.push_back({arr[i - 1], arr[i]});
            }
            else if (arr[i] - arr[i - 1] == min_val)
                ans.push_back({arr[i - 1], arr[i]});
        }

        return ans;
    }
};
// @lc code=end

// Note: sorting