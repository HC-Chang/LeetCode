/*
 * @lc app=leetcode id=2840 lang=cpp
 *
 * [2840] Check if Strings Can be Made Equal With Operations II
 */

// @lc code=start
class Solution
{
public:
    bool checkStrings(string s1, string s2)
    {
        int n = s1.size();
        if (n != s2.size())
            return false;
        array<array<char, 26>, 2> hash{};
        array<array<char, 26>, 2> zero{};
        for (int i = 0; i < n; i++)
        {
            ++hash[i % 2][s1[i] - 'a'];
            --hash[i % 2][s2[i] - 'a'];
        }

        return hash == zero;
    }
};
// @lc code=end

// Note: hash table