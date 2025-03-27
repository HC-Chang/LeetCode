/*
 * @lc app=leetcode id=2780 lang=cpp
 *
 * [2780] Minimum Index of a Valid Split
 */

// @lc code=start
class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        unordered_map<int, int> l, r;
        int n = nums.size();

        for (auto &nn : nums)
            r[nn]++;

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            r[num]--;
            l[num]++;

            if (l[num] * 2 > i + 1 &&
                r[num] * 2 > n - i - 1)
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end

// Note: hash map + sorting