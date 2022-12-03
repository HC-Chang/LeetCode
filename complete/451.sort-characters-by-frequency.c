/*
 * @lc app=leetcode id=451 lang=c
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
typedef struct
{
    int count;
    char c;
} DATA;

int compare(const void *a, const void *b)
{
    DATA *n1 = (DATA *)a;
    DATA *n2 = (DATA *)b;

    if (n1->count == n2->count)
        return n2->c - n1->c;

    return n2->count - n1->count;
}

char *frequencySort(char *s)
{
    int len = strlen(s);
    if (!len)
        return NULL;
        
    // '0' ~ 'z'
    // 48 ~ 122
    DATA *data = calloc(75, sizeof(DATA));
    for (int i = 0; i < 75; i++)
        data[i].c = i + '0';

    for (int i = 0; i < len; i++)
        ++data[s[i] - '0'].count;

    qsort(data, 75, sizeof(DATA), compare);

    char *ss = calloc(len + 1, sizeof(char));
    int ss_index = 0;
    for (int i = 0; i < 75; i++)
    {
        if (data[i].count == 0)
            continue;
        for (int j = 0; j < data[i].count; j++)
            ss[ss_index++] = data[i].c;
    }
    return ss;
}
// @lc code=end
