/*
 * @lc app=leetcode id=2094 lang=cpp
 *
 * [2094] Finding 3-Digit Even Numbers
 */

// @lc code=start
class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        unordered_set<int> s;
        int n = digits.size();
        int tmp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (i == j || j == k || i == k)
                        continue;
                    tmp = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (tmp >= 100 && tmp % 2 == 0)
                        s.insert(tmp);
                }
            }
        }

        vector<int> ans;
        for (const auto &ss : s)
            ans.push_back(ss);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

// Note: hash table