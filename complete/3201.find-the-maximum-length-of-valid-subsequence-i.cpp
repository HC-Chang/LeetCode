/*
 * @lc app=leetcode id=3201 lang=cpp
 *
 * [3201] Find the Maximum Length of Valid Subsequence I
 */

// @lc code=start
class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int max_cnt = 0;
        vector<vector<int>> patterns = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        for (auto &p : patterns)
        {
            int cnt = 0;
            for (int n : nums)
            {
                if (n % 2 == p[cnt % 2])
                    cnt++;
            }
            max_cnt = max(max_cnt, cnt);
        }
        return max_cnt;
    }
};
// @lc code=end

// Note: DP + greedy

// Official Solution