/*
 * @lc app=leetcode id=1455 lang=c
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
int isPrefixOfWord(char *sentence, char *searchWord)
{
    int n = strlen(sentence);
    int l = 0;
    int r = 0;
    int cnt = 1;
    int serch_size = strlen(searchWord);
    char s[serch_size + 1];
    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; i++)
    {
        if (sentence[i] == ' ')
        {
            r = i - 1;
            if (r - l + 1 >= serch_size)
            {
                memcpy(s, sentence + l, serch_size * sizeof(char));
                if (!strcmp(s, searchWord))
                    return cnt;
            }
            cnt++;
            l = i + 1;
        }
    }

    r = n - 1;
    if (r - l + 1 >= serch_size)
    {
        memcpy(s, sentence + l, serch_size * sizeof(char));
        if (!strcmp(s, searchWord))
            return cnt;
    }

    return -1;
}
// @lc code=end

// Note: two pointers