/*
 * @lc app=leetcode id=3024 lang=cpp
 *
 * [3024] Type of Triangle
 */

// @lc code=start
class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < 3; i++)
        {
            if (nums[i] == nums[i - 1])
                cnt++;
        }
        if (nums[0] == nums[2])
            cnt++;
        if (cnt == 3)
            return "equilateral";
        if (nums[0] + nums[1] <= nums[2])
            return "none";
        if (cnt == 1)
            return "isosceles";
        return "scalene";
    }
};
// @lc code=end

// Note: math + sorting