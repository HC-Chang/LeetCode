/*
 * @lc app=leetcode id=151 lang=c
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
// Solution 2:
char *reverseWords(char *s)
{
    int s_len = strlen(s);
    char *r = calloc(s_len + 1, sizeof(char));
    int end_idx;
    int en = 0;
    int cnt = 0;
    for (int i = s_len - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            if (en == 1)
            {
                strncat(r, s + i + 1, end_idx - i);
                strncat(r, " ", 1);
                cnt += end_idx - i + 1;
                en = 0;
            }
        }
        else
        {
            if (en == 0)
            {
                en = 1;
                end_idx = i;
            }
        }
    }
    if (en == 1 && s[0] != ' ')
    {
        strncat(r, s, end_idx + 1);
        cnt += end_idx + 1;
    }
    while (r[cnt - 1] == ' ')
        cnt--;
    r[cnt] = '\0';
    return r;
}
// @lc code=end

// Solution 1:
// void find_last_letter(char *s, int *start_index, int *len)
// {
//     *start_index = 0;
//     *len = 0;
//     int start = 0;
//     int s_len = strlen(s);
//     for (int i = 0; i < s_len; i++)
//     {
//         if (s[i] != ' ')
//         {
//             if (start)
//                 *len += 1;
//             else
//             {
//                 start = 1;
//                 *len = 1;
//                 *start_index = i;
//             }
//         }
//         else
//             start = 0;
//     }
// }

// char *reverseWords(char *s)
// {
//     char *arr = calloc(strlen(s) + 2, sizeof(char));
//     int start_index = 0;
//     int len = 0;
//     while (*s)
//     {
//         find_last_letter(s, &start_index, &len);
//         strncat(arr, s + start_index, len);
//         s[start_index] = '\0';
//         arr[strlen(arr)] = ' ';
//     }
//     while (arr[strlen(arr) - 1] == ' ')
//         arr[strlen(arr) - 1] = '\0';

//     return arr;
// }