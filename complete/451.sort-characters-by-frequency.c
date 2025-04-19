/*
 * @lc app=leetcode id=451 lang=c
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
typedef struct
{
    char c;
    int cnt;
} DATA;

int sort(const void *a, const void *b) { return (*(DATA *)b).cnt - (*(DATA *)a).cnt; };
// '0' ~ 'z'
// 48 ~ 122
#define SIZE 75
char *frequencySort(char *s)
{
    DATA d[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        d[i].c = '0' + i;
        d[i].cnt = 0;
    }
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        ++(d[s[i] - '0'].cnt);
    qsort(&d, SIZE, sizeof(DATA), sort);
    int idx = 0;
    int cnt;
    for (int i = 0; i < SIZE; i++)
    {
        cnt = d[i].cnt;
        if (cnt == 0)
            break;
        for (int j = 0; j < cnt; j++)
            s[idx++] = d[i].c;
    }
    return s;
}
// @lc code=end

// Note: hash table + counting + sorting