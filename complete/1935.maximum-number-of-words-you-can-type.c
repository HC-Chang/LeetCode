/*
 * @lc app=leetcode id=1935 lang=c
 *
 * [1935] Maximum Number of Words You Can Type
 */

// @lc code=start
int canBeTypedWords(char *text, char *brokenLetters)
{
    char s[26] = {};
    while (*brokenLetters)
        s[*brokenLetters++ - 'a'] = 1;

    int cnt = 0;
    bool can_type = true;
    while (*text)
    {
        if (*text == ' ')
        {
            if (can_type)
                cnt++;
            can_type = true;
            text++;
            continue;
        }
        if (s[*text - 'a'] == 1)
            can_type = false;
        text++;
    }
    if (can_type)
        cnt++;
    return cnt;
}
// @lc code=end

// Note: hash table
