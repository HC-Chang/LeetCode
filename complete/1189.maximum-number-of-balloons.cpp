/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> hash;
        for (char &c : text)
            hash[c]++;

        return min({hash['b'], hash['a'], hash['l'] / 2, hash['o'] / 2, hash['n']});
    }
};
// @lc code=end
