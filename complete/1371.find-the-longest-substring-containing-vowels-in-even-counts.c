/*
 * @lc app=leetcode id=1371 lang=c
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */

// @lc code=start
int findTheLongestSubstring(char *s)
{
    int prefix_xor = 0;
    int map[26] = {0};
    map['a' - 'a'] = 1;
    map['e' - 'a'] = 2;
    map['i' - 'a'] = 4;
    map['o' - 'a'] = 8;
    map['u' - 'a'] = 16;

    int mp[32];
    for (int i = 0; i < 32; i++)
        mp[i] = -1;
    int max_len = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        prefix_xor ^= map[s[i] - 'a'];
        if (mp[prefix_xor] == -1 && prefix_xor != 0)
            mp[prefix_xor] = i;

        max_len = fmax(max_len, i - mp[prefix_xor]);
    }

    return max_len;
}
// @lc code=end

// Note: hash table + bit manipulation + prefix sum

// Official Solution