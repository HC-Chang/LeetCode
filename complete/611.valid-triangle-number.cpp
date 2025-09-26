/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
class Solution
{
public:
    int binary_search(int i, int j, vector<int> &nums)
    {
        int n = nums.size();
        int l = j + 1;
        int r = n - 1;
        int target = nums[i] + nums[j];
        while (r >= l && r < n)
        {
            int mid = (l + r) / 2;
            if (nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l - j - 1;
    }

    int triangleNumber(vector<int> &nums)
    {
        int cnt = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
                cnt += binary_search(i, j, nums);
        }
        return cnt;
    }
};
// @lc code=end

// Note: sorting + binary search
