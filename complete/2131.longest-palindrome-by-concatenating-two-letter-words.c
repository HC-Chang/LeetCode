/*
 * @lc app=leetcode id=2131 lang=c
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

// @lc code=start
int longestPalindrome(char **words, int wordsSize)
{
    int count = 0;
    int **c_arr = malloc(26 * sizeof(int *));
    for (int i = 0; i < 26; i++)
        c_arr[i] = calloc(26, sizeof(int));
    int i1, i2;
    for (int i = 0; i < wordsSize; i++)
    {
        i1 = words[i][0] - 'a';
        i2 = words[i][1] - 'a';
        if (c_arr[i2][i1])
        {
            --c_arr[i2][i1];
            count += 4;
        }
        else
            ++c_arr[i1][i2];
    }
    for (int i = 0; i < 26; ++i)
    {
        if (c_arr[i][i])
        {
            count += 2;
            break;
        }
    }
    for (int i = 0; i < 26; i++)
        free(c_arr[i]);
    free(c_arr);
    return count;
}
// @lc code=end
