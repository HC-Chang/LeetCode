/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        const set<int> s = {1, 3, 7, 9};
        if (s.find(n % 10) == s.end())
            return false;
        while (n > 3)
        {
            if (n % 3 != 0)
                return false;
            n /= 3;
        }
        return true;
    }
};
// @lc code=end

// Note: math + recursion