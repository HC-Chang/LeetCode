/*
 * @lc app=leetcode id=3121 lang=c
 *
 * [3121] Count the Number of Special Characters II
 */

// @lc code=start
int numberOfSpecialChars(char *word)
{
    int v[26] = {0};
    while (*word)
    {
        if (!isupper(*word))
        {
            if (v[*word - 'a'] <= 1)
                v[*word - 'a'] = 1;
            else
                v[*word - 'a'] = 3;
        }
        else
        {
            if (v[*word - 'A'] == 1 || v[*word - 'A'] == 2)
                v[*word - 'A'] = 2;
            else
                v[*word - 'A'] = 3;
        }
        word++;
    }

    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (v[i] == 2)
            cnt++;
    }

    return cnt;
}
// @lc code=end

// Note: hash table