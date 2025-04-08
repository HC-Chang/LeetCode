/*
 * @lc app=leetcode id=3396 lang=cpp
 *
 * [3396] minimum-number-of-operations-to-make-elements-in-array-distinct
 */

// @lc code=start
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        unordered_map<int, int> h1;
        unordered_map<int, int> h2;
        for (auto nn : nums)
            ++h1[nn];
        for (auto h : h1)
        {
            if (h.second > 1)
                h2[h.first] = h.second;
        }
        if (h2.size() == 0)
            return 0;

        int cnt = 0;
        int n = nums.size();
        int i = 0;
        for (i = 0; i + 3 < n; i += 3)
        {
            for (int j = 0; i + j < n && j < 3; j++)
            {
                if (h2.find(nums[i + j]) != h2.end())
                {
                    if (--h2[nums[i + j]] == 1)
                        h2.erase(nums[i + j]);
                }
            }
            cnt++;
            if (h2.size() == 0)
                return cnt;
        }
        for (auto hh : h2)
        {
            if (hh.second > 1)
                return ++cnt;
        }
        return cnt;
    }
};
// @lc code=end

// Note: hash table