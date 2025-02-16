/*
 * @lc app=leetcode id=2762 lang=cpp
 *
 * [2762] Continuous Subarrays
 */

// @lc code=start
class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        int r = 0, l = 0;
        int cur_min, cur_max;
        long long window_len = 0, cnt = 0;
        int n = nums.size();
        cur_min = cur_max = nums[r];

        for (r = 0; r < n; r++)
        {
            cur_min = min(cur_min, nums[r]);
            cur_max = max(cur_max, nums[r]);

            if (cur_max - cur_min > 2)
            {
                window_len = r - l;
                cnt += (window_len * (window_len + 1) / 2);

                l = r;
                cur_min = cur_max = nums[r];

                while (l > 0 && abs(nums[r] - nums[l - 1]) <= 2)
                {
                    l--;
                    cur_min = min(cur_min, nums[l]);
                    cur_max = max(cur_max, nums[l]);
                }

                if (l < r)
                {
                    window_len = r - l;
                    cnt -= (window_len * (window_len + 1) / 2);
                }
            }
        }

        window_len = r - l;
        cnt += (window_len * (window_len + 1) / 2);

        return cnt;
    }
};
// @lc code=end

// Note: sliding window

// Official Solution