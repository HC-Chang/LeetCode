/*
 * @lc app=leetcode id=869 lang=c
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(char *)a - *(char *)b; }

void sorted_str_from_val(int val, char *s)
{
    sprintf(s, "%d", val);
    qsort(s, strlen(s), sizeof(char), sort);
}

bool reorderedPowerOf2(int n)
{
    char sort_n[32] = {0};
    char sort_val[32] = {0};
    sorted_str_from_val(n, sort_n);
    for (int i = 0; i < 31; ++i)
    {
        sorted_str_from_val(1 << i, sort_val);

        if (!strcmp(sort_n, sort_val))
            return true;
    }
    return false;
}
// @lc code=end

// Note: sorting