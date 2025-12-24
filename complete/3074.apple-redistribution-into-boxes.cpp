/*
 * @lc app=leetcode id=3074 lang=cpp
 *
 * [3074] Apple Redistribution into Boxes
 */

// @lc code=start
class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        sort(capacity.begin(), capacity.end(), greater<int>());

        int sum = accumulate(apple.begin(), apple.end(), 0);
        int cnt = 0;
        int n = capacity.size();
        while (sum > 0 && cnt < n)
            sum -= capacity[cnt++];
        return cnt;
    }
};
// @lc code=end

// Note: sorting