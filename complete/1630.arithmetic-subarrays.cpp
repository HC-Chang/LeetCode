/*
 * @lc app=leetcode id=1630 lang=cpp
 *
 * [1630] Arithmetic Subarrays
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int n = l.size();
        vector<int> copy;
        vector<bool> r_arr(n);
        int len;
        int diff;
        for (int i = 0; i < n; i++)
        {
            len = r[i] - l[i] + 1;
            copy.clear();
            for (int j = l[i]; j <= r[i]; j++)
                copy.push_back(nums[j]);
            sort(copy.begin(), copy.end());
            diff = copy[1] - copy[0];
            r_arr[i] = true;
            for (int j = 2; j < len; j++)
            {
                if (diff != copy[j] - copy[j - 1])
                {
                    r_arr[i] = false;
                    break;
                }
            }
        }

        return r_arr;
    }
};
// @lc code=end
