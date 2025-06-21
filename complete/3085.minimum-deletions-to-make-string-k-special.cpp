/*
 * @lc app=leetcode id=3085 lang=cpp
 *
 * [3085] Minimum Deletions to Make String K-Special
 */

// @lc code=start
class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        unordered_map<char, int> cnt;
        for (auto &ch : word)
            cnt[ch]++;
        
        int res = word.size();
        for (auto &[_, a] : cnt)
        {
            int deleted = 0;
            for (auto &[_, b] : cnt)
            {
                if (a > b)
                    deleted += b;
                else if (b > a + k)
                    deleted += b - (a + k);
            }
            res = min(res, deleted);
        }
        return res;
    }
};
// @lc code=end

// Note: hash table + + sorting + greedy

// Official Solution