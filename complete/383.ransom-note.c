/*
 * @lc app=leetcode id=383 lang=c
 *
 * [383] Ransom Note
 */

// @lc code=start

bool canConstruct(char *ransomNote, char *magazine)
{
    int r[26] = {0};
    int m[26] = {0};
    while (*ransomNote)
    {
        ++r[*ransomNote - 'a'];
        ransomNote++;
    }

    while (*magazine)
    {
        ++m[*magazine - 'a'];
        magazine++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (r[i] == 0)
        {
            continue;
        }
        if (r[i] > m[i])
        {
            return false;
        }
    }
    return true;
}
// @lc code=end
