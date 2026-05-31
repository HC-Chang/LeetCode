/*
 * @lc app=leetcode id=2126 lang=cpp
 *
 * [2126] Destroying Asteroids
 */

// @lc code=start
class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        int n = asteroids.size();
        sort(asteroids.begin(), asteroids.end());
        if (mass < asteroids[0])
            return false;

        long long p = asteroids[0] + mass;
        for (int i = 1; i < n; i++)
        {
            if (p >= asteroids[i])
                p += asteroids[i];
            else
                return false;
        }

        return true;
    }
};
// @lc code=end

// Note: sort