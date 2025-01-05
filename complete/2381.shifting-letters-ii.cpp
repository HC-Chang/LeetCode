/*
 * @lc app=leetcode id=2381 lang=cpp
 *
 * [2381] Shifting Letters II
 */

// @lc code=start
class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.size();
        vector<int> diff(n);
        for (auto ss : shifts)
        {
            if (ss[2] == 0)
                ss[2] = -1;
            diff[ss[0]] += ss[2];
            if (ss[1] + 1 < n)
                diff[ss[1] + 1] -= ss[2];
        }

        int diff_cache = 0;
        for (int i = 0; i < n; i++)
        {
            diff_cache += diff[i];
            while (diff_cache < 0)
                diff_cache += 26;
            s[i] = 'a' + (s[i] - 'a' + diff_cache) % 26;
        }
        return s;
    }
};
// @lc code=end

// Note: prefix sum