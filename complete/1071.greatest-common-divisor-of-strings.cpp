/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        // Check if they have non-zero GCD string.
        if (str1 + str2 != str2 + str1)
        {
            return "";
        }

        // Get the GCD of the two lengths.
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};
// @lc code=end

// Official Solution - GCD