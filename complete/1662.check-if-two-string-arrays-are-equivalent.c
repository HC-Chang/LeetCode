/*
 * @lc app=leetcode id=1662 lang=c
 *
 * [1662] Check If Two String Arrays are Equivalent
 */

// @lc code=start

bool arrayStringsAreEqual(char **word1, int word1Size, char **word2, int word2Size)
{
    // Solution 1:
    if (word1[0] == NULL && word2[0] == NULL)
        return true;
    else if (word1[0] == NULL || word2[0] == NULL)
        return false;

    int size1 = 0;
    int size2 = 0;
    char *w1 = word1[0];
    char *w2 = word2[0];
    while (*w1 != '\0' || *w2 != '\0')
    {
        if (*w1 != *w2)
            return false;
        w1++;
        w2++;
        if (*w1 == '\0' && size1 < word1Size - 1)
            w1 = word1[++size1];
        if (*w2 == '\0' && size2 < word2Size - 1)
            w2 = word2[++size2];
    }

    if (*w1 != *w2)
        return false;

    return true;

    // Solution 2:
    
    // char s1[1000] = "";
    // char s2[1000] = "";
    // int i;
    // for (i = 0; i < word1Size; i++)
    // {
    //     strcat(s1, word1[i]);
    // }
    // for (i = 0; i < word2Size; i++)
    // {
    //     strcat(s2, word2[i]);
    // }
    // return !strcmp(s1, s2);
}
// @lc code=end
