/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++)
            p.push_back({nums[i], i});
        sort(p.begin(), p.end());

        int start = p[0].second;
        while (n > 0 && nums[(start - 1 + n) % n] == nums[(start) % n])
        {
            start = (start - 1 + n) % n;
            n--;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[(start + 1 + i) % n] - nums[(start + i) % n] < 0)
                return false;
        }

        return true;
    }
};
// @lc code=end
