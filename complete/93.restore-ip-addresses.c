/*
 * @lc app=leetcode id=93 lang=c
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char *new_valid_ip(int seg1, int seg2, int seg3, char *s)
{
    int s_len = strlen(s);
    if (seg3 > s_len)
        return "";
    char *r = calloc((s_len + 4), sizeof(char));

    strncpy(r, s, seg1);
    r[seg1] = '.';
    strncpy(r + seg1 + 1, s + seg1, seg2 - seg1);
    r[seg2 + 1] = '.';
    strncpy(r + seg2 + 2, s + seg2, seg3 - seg2);
    r[seg3 + 2] = '.';
    strncpy(r + seg3 + 3, s + seg3, s_len - seg3);

    return r;
}

int is_invalid_number(int start, int count, char *s)
{
    if (count > 3 || count <= 0)
        return 1;
    else if (count == 3 && (s[start] - '2' > 0 || s[start] - '0' <= 0))
        return 1;
    else if (count == 2 && (s[start] - '0' <= 0))
        return 1;
    else
    {
        char tmp[4] = {0};
        strncpy(&tmp, s + start, count);
        int ip = atoi(tmp);
        if (ip < 0 || ip > 255)
            return 1;
    }
    return 0;
}

char **restoreIpAddresses(char *s, int *returnSize)
{
    int s_len = strlen(s);

    if (s_len < 4 || s_len > 12)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 1;
    char **r = malloc(*returnSize * sizeof(char *));

    switch (s_len)
    {
    case 4:
        r[0] = new_valid_ip(1, 2, 3, s);
        return r;
        break;

    case 12:
        if ((is_invalid_number(0, 3, s) |
             is_invalid_number(3, 3, s) |
             is_invalid_number(6, 3, s) |
             is_invalid_number(9, 3, s)) == 1)
        {
            *returnSize = 0;
            free(r);
            return NULL;
        }
        r[0] = new_valid_ip(3, 6, 9, s);
        return r;
        break;
    }

    char *tmp;

    for (int i = s_len - 1; i >= 2; i--)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            for (int k = j - 1; k >= 0; k--)
            {
                if ((is_invalid_number(0, k, s) |
                     is_invalid_number(k, j - k, s) |
                     is_invalid_number(j, i - j, s) |
                     is_invalid_number(i, s_len - i, s)) == 1)
                    continue;

                tmp = new_valid_ip(k, j, i, s);

                r[*returnSize - 1] = tmp;
                r = realloc(r, (++*returnSize) * sizeof(char *));
            }
        }
    }
    --*returnSize;

    return r;
}
// @lc code=end

// Iterative

// Find 4 segments in the string,
// and insert 3 dot to make sure that be a valid IP address

// IP: 0~255.0~255.0~255.0~255
// s_len: 4~12
// return char [][ s_len + 3 ]