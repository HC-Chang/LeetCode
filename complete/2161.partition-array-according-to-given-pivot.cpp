/*
 * @lc app=leetcode id=2161 lang=cpp
 *
 * [2161] Partition Array According to Given Pivot
 */

// @lc code=start
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> l;
        vector<int> r;
        int cnt = 0;
        for (auto n : nums)
        {
            if (n < pivot)
                l.push_back(n);
            else if (n > pivot)
                r.push_back(n);
            else
                cnt++;
        }

        for (int i = 0; i < cnt; i++)
            l.push_back(pivot);
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
};
// @lc code=end

// Note: two pointers