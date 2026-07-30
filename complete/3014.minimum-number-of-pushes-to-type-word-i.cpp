/*
 * @lc app=leetcode id=3014 lang=cpp
 *
 * [3014] Minimum Number of Pushes to Type Word I
 */

// @lc code=start
class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> v(26, 0);
        for (auto &c : word)
            ++v[c - 'a'];
        sort(v.begin(), v.end(), greater<int>());
        int idx = 0;
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 0)
                break;
            if (i % 8 == 0)
                idx++;
            ans += v[i] * idx;
        }

        return ans;
    }
};
// @lc code=end

// Note: math + greedy