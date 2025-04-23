/*
 * @lc app=leetcode id=1399 lang=cpp
 *
 * [1399] Count Largest Group
 */

// @lc code=start
class Solution
{
public:
    int countLargestGroup(int n)
    {
        unordered_map<int, int> hash;
        int max_val = 0;
        int tmp;
        int tmp_sum;
        for (int i = 1; i <= n; i++)
        {
            tmp = i;
            tmp_sum = 0;
            while (tmp)
            {
                tmp_sum += tmp % 10;
                tmp /= 10;
            }
            ++hash[tmp_sum];
            max_val = max(max_val, hash[tmp_sum]);
        }

        int cnt = 0;
        for (auto h : hash)
        {
            if (h.second == max_val)
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end

// Note: hash table
