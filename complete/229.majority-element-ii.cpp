/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> r;
        int n1 = 0, n2 = 0, cnt1 = 0, cnt2 = 0, n = nums.size();
        for (int num : nums)
        {
            if (num == n1)
                ++cnt1;
            else if (num == n2)
                ++cnt2;
            else if (cnt1 == 0)
            {
                n1 = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                n2 = num;
                cnt2 = 1;
            }
            else
            {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = cnt2 = 0;
        for (int num : nums)
        {
            if (num == n1)
                ++cnt1;
            else if (num == n2)
                ++cnt2;
        }
        if (cnt1 > n / 3)
            r.push_back(n1);
        if (cnt2 > n / 3)
            r.push_back(n2);
        return r;
    }
};
// @lc code=end
