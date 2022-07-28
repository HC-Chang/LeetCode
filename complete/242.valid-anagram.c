/*
 * @lc app=leetcode id=242 lang=c
 *
 * [242] Valid Anagram
 */

// @lc code=start

bool isAnagram(char *s, char *t)
{
    int s_len = strlen(s);
    if (s_len != strlen(t))
    {
        return false;
    }

    char map[26] = {0};
    for (int i = 0; i < s_len; i++)
    {
        map[s[i] - 'a']++;
        map[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if(map[i] != 0)
        {
            return false;
        }
    }
    return true;
}
// @lc code=end
