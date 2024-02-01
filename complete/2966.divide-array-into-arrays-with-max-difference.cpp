/*
 * @lc app=leetcode id=2966 lang=cpp
 *
 * [2966] Divide Array Into Arrays With Max Difference
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int diff;

        vector<vector<int>> r(nums.size() / 3, vector<int>(3));

        int grp = 0;
        int idx = 0;
        r[grp][idx++] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            diff = nums[i] - r[grp][0];
            if (diff > k && idx != 0)
                return vector<vector<int>>();
            else
            {
                r[grp][idx++] = nums[i];
                if (idx == 3)
                {
                    idx = 0;
                    grp++;
                }
            }
        }

        return r;
    }
};
// @lc code=end

// Note: sorting