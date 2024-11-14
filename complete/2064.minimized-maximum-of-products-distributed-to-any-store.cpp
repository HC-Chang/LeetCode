/*
 * @lc app=leetcode id=2064 lang=cpp
 *
 * [2064] Minimized Maximum of Products Distributed to Any Store
 */

// @lc code=start
class Solution
{
public:
    bool can_distribute(int x, vector<int> &quantities, int n)
    {
        int j = 0;
        int remaining = quantities[j];

        for (int i = 0; i < n; i++)
        {
            if (remaining <= x)
            {
                j++;
                if (j == quantities.size())
                    return true;
                else
                    remaining = quantities[j];
            }
            else
                remaining -= x;
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int left = 0;
        int right = *max_element(quantities.begin(), quantities.end());
        int middle;
        while (left < right)
        {
            middle = (left + right) / 2;
            if (can_distribute(middle, quantities, n))
                right = middle;
            else
                left = middle + 1;
        }
        return left;
    }
};
// @lc code=end

// Note: binary search

// Official Solution