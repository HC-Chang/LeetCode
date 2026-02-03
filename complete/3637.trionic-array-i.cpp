/*
 * @lc app=leetcode id=3637 lang=cpp
 *
 * [3637] Trionic Array I
 */

// @lc code=start
class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 4)
            return false;
        if (nums[1] <= nums[0])
            return false;
        int cnt = 0;
        bool flag = 1;
        for (int i = 1; i < n; i++)
        {
            if ((flag && nums[i] < nums[i - 1]) || (!flag && nums[i] > nums[i - 1]))
            {
                cnt++;
                flag = !flag;
            }
            else if (nums[i] == nums[i - 1])
                return false;
        }

        return cnt == 2;
    }
};
// @lc code=end
