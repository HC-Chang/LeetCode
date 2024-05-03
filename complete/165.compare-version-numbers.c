/*
 * @lc app=leetcode id=165 lang=c
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
int compareVersion(char *version1, char *version2)
{
    int n1 = strlen(version1);
    int n2 = strlen(version2);
    int arr1[500] = {0};
    int arr2[500] = {0};
    int idx_arr1 = 0;
    int idx_arr2 = 0;

    int idx = 0;
    for (int i = 0; i < n1; i++)
    {
        if (version1[i] == '.')
        {
            version1[i] = '\0';
            arr1[idx_arr1++] = atoi(version1 + idx);
            idx = i + 1;
        }
    }
    arr1[idx_arr1++] = atoi(version1 + idx);

    idx = 0;
    for (int i = 0; i < n2; i++)
    {
        if (version2[i] == '.')
        {
            version2[i] = '\0';
            arr2[idx_arr2++] = atoi(version2 + idx);
            idx = i + 1;
        }
    }
    arr2[idx_arr2++] = atoi(version2 + idx);

    for (int i = 0; i < fmax(idx_arr1, idx_arr2); i++)
    {
        int v1 = i < idx_arr1 ? arr1[i] : 0;
        int v2 = i < idx_arr2 ? arr2[i] : 0;
        if (v1 != v2)
            return v1 < v2 ? -1 : 1;
    }

    return 0;
}
// @lc code=end

// Note: two pointers / stack