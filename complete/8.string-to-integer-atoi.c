/*
 * @lc app=leetcode id=8 lang=c
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start

#define INT_MAX 2147483647
#define INT_MIN -2147483648

// space : 32
// + : 43
// - : 45
// 0~9 : 48~57

int converI(char *s)
{
    return *s - '0';
}

int myAtoi(char *s)
{

    // 去除前段空白
    while (*s == ' ')
    {
        s++;
    }

    // 判斷正負
    int sign = 1;
    if (*s == '+' || *s == '-')
    {
        if (*s == '-')
        {
            sign = -1;
        }
        s++;
    }

    // 確認答案於 int 範圍
    long long ans = 0;
    while (*s != '\0' && *s <= '9' && *s >= '0')
    {
        ans = ans * 10 + converI(s);
        if (ans * sign > INT_MAX)
        {
            return INT_MAX;
        }
        if (ans * sign < INT_MIN)
        {
            return INT_MIN;
        }

        s++;
    }
    ans *= sign;

    return ans;
}
// @lc code=end
