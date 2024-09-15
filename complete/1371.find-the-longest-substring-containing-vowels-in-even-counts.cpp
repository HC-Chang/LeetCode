/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */

// @lc code=start
class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int prefix_xor = 0;
        vector<int> map(26);
        map['a' - 'a'] = 1;
        map['e' - 'a'] = 2;
        map['i' - 'a'] = 4;
        map['o' - 'a'] = 8;
        map['u' - 'a'] = 16;

        vector<int> mp(32, -1);
        int max_len = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            prefix_xor ^= map[s[i] - 'a'];
            if (mp[prefix_xor] == -1 && prefix_xor != 0)
                mp[prefix_xor] = i;

            max_len = max(max_len, i - mp[prefix_xor]);
        }

        return max_len;
    }
};
// @lc code=end

// Note: hash table + bit manipulation + prefix sum

// Official Solution