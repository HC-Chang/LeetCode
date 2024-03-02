/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
// Solution 2: two pointer
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ll, rr;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            ll = nums[l] * nums[l];
            rr = nums[r] * nums[r];
            if (ll > rr)
            {
                ans[i] = ll;
                l++;
            }
            else
            {
                ans[i] = rr;
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end

// Note: sorting + two pointer

// Sloution 1: sort
// class Solution
// {
// public:
//     vector<int> sortedSquares(vector<int> &nums)
//     {
//         for (int i = 0; i < nums.size(); i++)
//             nums[i] *= nums[i];
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };