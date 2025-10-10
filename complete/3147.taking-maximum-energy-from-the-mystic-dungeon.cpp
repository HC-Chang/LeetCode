/*
 * @lc app=leetcode id=3147 lang=cpp
 *
 * [3147] Taking Maximum Energy From the Mystic Dungeon
 */

// @lc code=start
class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        int n = energy.size();
        for (int i = 0; i < n - k; i++)
            energy[i + k] = max(energy[i + k] + energy[i], energy[i + k]);
        for (int i = n - k; i < n; i++)
            energy[n - 1] = max(energy[n - 1], energy[i]);
        return energy[n - 1];
    }
};
// @lc code=end

// Note: prefix sum + greedy