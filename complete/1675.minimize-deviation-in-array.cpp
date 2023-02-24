/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
 */

// @lc code=start
class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        multiset<int> Set;
        for (auto x : nums)
        {
            if (x % 2 == 0)
                Set.insert(x);
            else
                Set.insert(x * 2);
        }

        int r = INT_MAX;
        int k;
        while (!Set.empty())
        {
            r = min(r, *Set.rbegin() - *Set.begin());
            k = *Set.rbegin();
            Set.erase(prev(Set.end()));
            if (k % 2 == 1)
                break;
            else
                Set.insert(k / 2);
        }
        return r;
    }
};

// @lc code=end
