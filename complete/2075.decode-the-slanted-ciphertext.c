/*
 * @lc app=leetcode id=2075 lang=c
 *
 * [2075] Decode the Slanted Ciphertext
 */

// @lc code=start
char *decodeCiphertext(char *encodedText, int rows)
{
    int n = strlen(encodedText);
    if (rows == 1 || n == 0)
        return encodedText;
    int nn = n / rows;
    char *ans = malloc(n * sizeof(char));
    int idx = 0;
    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (j * nn + i + j >= n)
                break;
            ans[idx++] = encodedText[j * nn + i + j];
        }
    }
    while (ans[idx - 1] == ' ')
        idx--;
    ans[idx] = '\0';
    return ans;
}
// @lc code=end
