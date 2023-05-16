/*
 * @lc app=leetcode id=168 lang=c
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
char *convertToTitle(int columnNumber)
{
    int count = 0;
    int *arr = calloc(8, sizeof(int));
    while (columnNumber > 0)
    {
        arr[count++] = (columnNumber - 1) % 26;
        columnNumber = (columnNumber - 1) / 26;
    }
    char *s = calloc(count + 1, sizeof(char));
    for (int i = 0; i < count; i++)
        s[i] = arr[count - 1 - i] + 'A';

    s[count] = '\0';
    free(arr);
    return s;
}
// @lc code=end
