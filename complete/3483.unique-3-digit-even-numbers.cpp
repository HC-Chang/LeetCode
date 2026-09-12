/*
 * @lc app=leetcode id=3483 lang=cpp
 *
 * [3483] Unique 3-Digit Even Numbers
 */

// @lc code=start
class Solution
{
public:
    int totalNumbers(vector<int> &digits)
    {
        unordered_map<int, int> hash;
        for (auto &d : digits)
            ++hash[d];
        int cnt = 0;
        for (int i = 0; i < 10; i += 2)
        {
            if (hash[i] <= 0)
                continue;
            --hash[i];
            for (int j = 0; j < 10; j++)
            {
                if (hash[j] <= 0)
                    continue;
                --hash[j];
                for (int k = 1; k < 10; k++)
                {
                    if (hash[k] <= 0)
                        continue;

                    cnt++;
                }
                ++hash[j];
            }
            ++hash[i];
        }

        return cnt;
    }
};
// @lc code=end

// Note: hash table + recursion