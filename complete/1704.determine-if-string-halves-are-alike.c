/*
 * @lc app=leetcode id=1704 lang=c
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
int counting(char c, int i)
{
    switch (c)
    {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
        i++;
        break;
    }
    return i;
}

bool halvesAreAlike(char *s)
{
    int count[2] = {0};
    for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j)
    {
        count[0] = counting(s[i], count[0]);
        count[1] = counting(s[j], count[1]);
    }
    return count[0] == count[1];
}
// @lc code=end
