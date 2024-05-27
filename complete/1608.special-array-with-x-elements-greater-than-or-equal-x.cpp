/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        int cnt;
        for (int i = 0; i < n + 1; i++)
        {
            cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] >= i)
                    cnt++;
            }
            if (cnt == i)
                return i;
        }

        return -1;
    }
};
// @lc code=end
