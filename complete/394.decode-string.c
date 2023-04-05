/*
 * @lc app=leetcode id=394 lang=c
 *
 * [394] Decode String
 */

// @lc code=start
#define BUF_SIZE 1000
char *decodeString(char *s)
{
    char *str1 = malloc(sizeof(char) * BUF_SIZE*2); 
    char *str2 = malloc(sizeof(char) * BUF_SIZE*2); 
    int len = strlen(s);
    int i_1 = 0, i_2 = 0;
    int sum, x;
    int mm;
    char *buf = malloc(sizeof(char) * BUF_SIZE*2); 
    for (int i = 0; i < len; i++) 
    {
        if (s[i] == '[') 
        {
            str1[i_1++] = '[';
            str2[i_2++] = '[';
        }
        else if (s[i] == ']')
        {
            sum = 0;
            x = 10;
            sum += (str1[i_1 - 2] - '0');
            i_1 = i_1 - 2;
            while (i_1 > 0 && str1[i_1 - 1] != '[')
            {
                sum += (str1[i_1 - 1] - '0') * x;
                i_1--;
                x *= 10;
            }

            mm = BUF_SIZE;
            i_2--;
            while (str2[i_2] != '[')
                buf[--mm] = str2[i_2--];
            while (sum--)
            {
                for (int j = mm; j < BUF_SIZE; j++)
                    str2[i_2++] = buf[j];
            }
        }
        else if (!isalpha(s[i]))
            str1[i_1++] = s[i];
        else
            str2[i_2++] = s[i];
    }
    str2[i_2] = '\0';
    str2 = realloc(str2, i_2*sizeof(int));
    free(str1);
    free(buf);
    return str2;
}

// @lc code=end
