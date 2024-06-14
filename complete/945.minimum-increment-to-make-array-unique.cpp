/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
#define SIZE 101001
class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int hash[SIZE] = {0};
        int cnt = 0;
        int offset = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (!hash[nums[i]])
                ++hash[nums[i]];
            else
            {
                while (nums[i] + offset < SIZE - 1 &&
                       (hash[nums[i] + offset]) > 0)
                    offset++;
                hash[nums[i] + offset] = 1;
                cnt += offset;
                offset = 1;
            }
        }

        return cnt;
    }
};
// @lc code=end

// Note: sorting + counting