/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
class Solution
{
public:
    int binary_search(int spell, long long success, vector<int> &arr)
    {
        int left = 0;
        int right = arr.size() - 1;
        int middle;
        long long product;
        while (left <= right)
        {
            middle = left + (right - left) / 2;
            product = (long long)spell * arr[middle];
            if (product >= success)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return left;
    }

    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                                long long success)
    {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        int n = potions.size();
        for (auto s : spells)
            ans.push_back(n -
                          binary_search(s, success, potions));
        return ans;
    }
};
// @lc code=end
