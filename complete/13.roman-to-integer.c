/*
 * @lc app=leetcode id=13 lang=c
 *
 * [13] Roman to Integer
 */

// @lc code=start

int r2i(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
    return 0;
}

int romanToInt(char *s)
{
    int s_len = strlen(s);
    int temp = 0;
    int val = 0;

    for (int i = 0; i < s_len; i++)
    {
        if (i == s_len - 1)
        {
            val += r2i(s[i]);
            break;
        }
        // 非大至小排序
        if ((temp = r2i(s[i + 1]) - r2i(s[i])) > 0)
        {
            val += temp;
            i++;
            temp = 0;

            continue;
        }
        val += r2i(s[i]);
    }

    return val;
}
// @lc code=end
// Order: M > D > C > L > X > V > I
// 若非依照上述大小排序，則大數字減小數字
// ex. IV= 5-1 = 4