/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
// Solution 2:

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};
// @lc code=end

// Note: two pointers

// Solution 1:

// class Solution
// {
// public:
//     void reverseString(vector<char> &s)
//     {
//         char c;
//         int l = 0;
//         int r = s.size() - 1;
//         while (l < r)
//         {
//             c = s[l];
//             s[l++] = s[r];
//             s[r--] = c;
//         }
//     }
// };