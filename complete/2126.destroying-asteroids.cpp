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

        long long cur = mass;
        for (auto &a: asteroids)
        {
            if (cur >= a)
                cur += a;
            else
                return false;
        }

        return true;
    }
};
// @lc code=end

// Note: sort