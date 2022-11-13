/*
 * @lc app=leetcode id=151 lang=c
 *
 * [151] Reverse Words in a String
 */

// @lc code=start

void find_last_letter(char *s, int *start_index, int *len)
{
    *start_index = 0;
    *len = 0;
    int start = 0;
    int s_len = strlen(s);
    for (int i = 0; i < s_len; i++)
    {
        if (s[i] != ' ')
        {
            if (start)
                *len += 1;
            else
            {
                start = 1;
                *len = 1;
                *start_index = i;
            }
        }
        else
            start = 0;
    }
}

char *reverseWords(char *s)
{
    char *arr = calloc(strlen(s) + 2, sizeof(char));
    int start_index = 0;
    int len = 0;
    while (*s)
    {
        find_last_letter(s, &start_index, &len);
        strncat(arr, s + start_index, len);
        s[start_index] = '\0';
        arr[strlen(arr)] = ' ';
    }
    while (arr[strlen(arr) - 1] == ' ')
        arr[strlen(arr) - 1] = '\0';

    return arr;
}
// @lc code=end
