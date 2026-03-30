/*
 * @lc app=leetcode id=2840 lang=c
 *
 * [2840] Check if Strings Can be Made Equal With Operations II
 */

// @lc code=start
bool checkStrings(char *s1, char *s2)
{
    int n = strlen(s1);
    if (n != strlen(s2))
        return false;
    int freq1[26] = {}, freq2[26] = {};
    for (int i = 0; i < n; i += 2)
    {
        ++freq1[s1[i] - 'a'];
        ++freq2[s2[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i)
    {
        if (freq1[i] != freq2[i])
            return false;
    }
    memset(freq1, 0, sizeof(freq1));
    memset(freq2, 0, sizeof(freq2));
    for (int i = 1; i < n; i += 2)
    {
        ++freq1[s1[i] - 'a'];
        ++freq2[s2[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i)
    {
        if (freq1[i] != freq2[i])
            return false;
    }
    return true;
}
// @lc code=end

// Note: hash table