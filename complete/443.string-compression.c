/*
 * @lc app=leetcode id=443 lang=c
 *
 * [443] String Compression
 */

// @lc code=start

void print_count(int val, int *index, char *chars)
{
    char c[5];
    sprintf(c, "%d", val);
    int c_len = strlen(c);
    for (int i = 0; i < c_len; i++)
        chars[(*index)++] = c[i];
}

int compress(char *chars, int charsSize)
{
    if (charsSize == 1)
        return charsSize;

    int index = 0;

    char c = chars[0];
    int c_count = 1;

    for (int i = 1; i < charsSize; i++)
    {
        if (c == chars[i])
            ++c_count;
        else if (c != chars[i])
        {
            chars[index++] = c;
            if (c_count > 1)
                print_count(c_count, &index, chars);
            c = chars[i];
            c_count = 1;
        }
    }
    chars[index++] = c;
    if (c_count > 1)
        print_count(c_count, &index, chars);

    return index;
}
// @lc code=end
