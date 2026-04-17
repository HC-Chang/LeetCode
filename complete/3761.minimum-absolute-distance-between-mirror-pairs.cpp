/*
 * @lc app=leetcode id=3761 lang=cpp
 *
 * [3761] Minimum Absolute Distance Between Mirror Pairs
 */

// @lc code=start
class Solution
{
public:
    int minMirrorPairDistance(vector<int> &nums)
    {
        unordered_map<int, vector<int>> hash;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            hash[nums[i]].push_back(i);

        int dis = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            string rev_str = to_string(nums[i]);
            reverse(rev_str.begin(), rev_str.end());
            int rev = stoi(rev_str);
            if (hash.find(rev) != hash.end())
            {
                for (auto &h : hash[rev])
                {
                    if (h > i)
                    {
                        dis = min(dis, h - i);
                        if (dis == 1)
                            return 1;
                        break;
                    }
                }
            }
        }
        if (dis == INT_MAX)
            dis = -1;
        return dis;
    }
};
// @lc code=end

// Note: hash tabel + math