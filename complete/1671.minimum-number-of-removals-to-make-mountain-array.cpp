/*
 * @lc app=leetcode id=1671 lang=cpp
 *
 * [1671] Minimum Number of Removals to Make Mountain Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> getLongestIncreasingSubsequenceLength(vector<int> &v)
    {
        vector<int> lisLen(v.size(), 1);
        vector<int> lis = {v[0]};

        for (int i = 1; i < v.size(); i++)
        {
            int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();

            if (index == lis.size())
                lis.push_back(v[i]);
            else
                lis[index] = v[i];

            lisLen[i] = lis.size();
        }
        return lisLen;
    }

    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis_length = getLongestIncreasingSubsequenceLength(nums);

        reverse(nums.begin(), nums.end());
        vector<int> lds_length = getLongestIncreasingSubsequenceLength(nums);
        reverse(lds_length.begin(), lds_length.end());

        int min_remove = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (lis_length[i] > 1 && lds_length[i] > 1)
                min_remove =
                    min(min_remove, n - lis_length[i] - lds_length[i] + 1);
        }

        return min_remove;
    }
};
// @lc code=end

// Note: DP + binary search

// Official Solution