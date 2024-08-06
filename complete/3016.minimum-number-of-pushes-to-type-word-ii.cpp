/*
 * @lc app=leetcode id=3016 lang=cpp
 *
 * [3016] Minimum Number of Pushes to Type Word II
 */

// @lc code=start
class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> hash(26);
        for (auto w : word)
            ++hash[w - 'a'];

        sort(hash.begin(), hash.end(), greater<int>());
        int sum_cnt = 0;
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            if (hash[i] == 0)
                break;
            if (i % 8 == 0)
                cnt++;
            sum_cnt += hash[i] * cnt;
        }

        return sum_cnt;
    }
};
// @lc code=end

// Note: hash table + sorting + counting