/*
 * @lc app=leetcode id=3517 lang=cpp
 *
 * [3517] Smallest Palindromic Rearrangement I
 */

// @lc code=start

// Solution 2:

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int arr[26] = {0};
        for (auto &c : s)
            ++arr[c - 'a'];

        string ans = "";
        string tmp = "";
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < arr[i] / 2; j++)
                ans += 'a' + i;
            if (arr[i] % 2 == 1)
                tmp = 'a' + i;
        }
        int idx = ans.size() - 1;
        ans += tmp;
        for (int i = idx; i >= 0; i--)
            ans += ans[i];

        return ans;
    }
};
// @lc code=end

// Note: sorting

// Solution 1:

// class Solution
// {
// public:
//     string smallestPalindrome(string s)
//     {
//         unordered_map<char, int> hash;
//         for (auto &c : s)
//             ++hash[c];
//         vector<pair<char, int>> v;
//         for (auto &h : hash)
//             v.push_back({h.first, h.second});
//         sort(v.begin(), v.end());

//         s = "";
//         char tmp = ' ';
//         for (auto &vv : v)
//         {
//             for (int i = 0; i < vv.second / 2; i++)
//                 s += vv.first;
//             if (vv.second % 2 == 1)
//                 tmp = vv.first;
//         }

//         string ans = s;
//         reverse(s.begin(), s.end());
//         if (tmp == ' ')
//             return ans + s;
//         return ans + tmp + s;
//     }
// };