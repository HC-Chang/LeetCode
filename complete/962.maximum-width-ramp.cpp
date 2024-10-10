/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> indices(n);

        for (int i = 0; i < n; i++)
            indices[i] = i;

        sort(indices.begin(), indices.end(), [&](int i, int j)
             { return nums[i] != nums[j] ? nums[i] < nums[j] : i < j; });

        int min_index = n;
        int max_width = 0;

        for (int i = 0; i < n; i++)
        {
            max_width = max(max_width, indices[i] - min_index);
            min_index = min(min_index, indices[i]);
        }

        return max_width;
    }
};
// @lc code=end

// Note: stack / monotonic stack

// Official Solution
