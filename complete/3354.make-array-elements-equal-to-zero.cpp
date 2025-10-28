/*
 * @lc app=leetcode id=3354 lang=cpp
 *
 * [3354] Make Array Elements Equal to Zero
 */

// @lc code=start
class Solution
{
public:
    int countValidSelections(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> l_arr(n), r_arr(n);
        l_arr[0] = nums[0];
        r_arr[n - 1] = nums[n - 1];
        vector<int> idx;
        if (nums[0] == 0)
            idx.push_back(0);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == 0)
                idx.push_back(i);
            l_arr[i] = l_arr[i - 1] + nums[i];
            r_arr[n - 1 - i] = r_arr[n - i] + nums[n - 1 - i];
        }

        int cnt = 0;
        for (auto &i : idx)
        {
            int val = abs(l_arr[i] - r_arr[i]);
            if (val <= 1)
            {
                if (val == 1)
                    cnt++;
                else
                    cnt += 2;
            }
        }
        return cnt;
    }
};
// @lc code=end

// Note: prefix sum + simulation