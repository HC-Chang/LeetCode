/*
 * @lc app=leetcode id=1108 lang=c
 *
 * [1108] Defanging an IP Address
 */

// @lc code=start

char *defangIPaddr(char *address)
{
    char *r = calloc(strlen(address) + 7, sizeof(char));
    char *start = r;
    while (*address)
    {
        if (*address == '.')
        {
            *r++ = '[';
            *r++ = '.';
            *r++ = ']';
            *address++;
        }
        else
            *r++ = *address++;

    }

    return start;
}
// @lc code=end
