/*
 * @lc app=leetcode id=49 lang=c
 *
 * [49] Group Anagrams
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void sorting_strs(char *unsort, char *sort)
{
    int characters[26] = {0};
    int len_unsort = strlen(unsort);
    for (int i = 0; i < len_unsort; i++)
    {
        ++characters[unsort[i] - 'a'];
    }
    int sort_index = 0;
    for (int i = 0; i < 26; i++)
    {
        if (sort_index >= len_unsort)
        {
            sort[sort_index] = '\0';
            return;
        }
        for (int j = 0; j < characters[i]; j++)
        {
            sort[sort_index] = 'a' + i;
            sort_index++;
        }
    }
}

int count_dif(char **arr, int count, int *dif_arr, int *index)
{
    int dif = 0;
    int size = 0;

    for (int i = 0; i < count; i++)
    {
        if (dif_arr[i] == 0)
        {
            dif++;
            size = 1;
            dif_arr[i] = dif;
            for (int j = i + 1; j < count; j++)
            {
                if (dif_arr[j] == 0)
                {
                    if (!strcmp(arr[i], arr[j]))
                    {
                        dif_arr[j] = dif;
                        index[j] = size;

                        size++;
                    }
                }
            }
        }
    }

    // for (int i = 0; i < count; i++)
    // {
    //     printf("%i\n", dif_arr[i]);
    // }

    return dif;
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    char ***groups;
    char **sorted_strs = calloc(strsSize, sizeof(char *));
    int *groups_index = calloc(strsSize, sizeof(int));
    int *index = calloc(strsSize, sizeof(int));

    // sort strs
    for (int i = 0; i < strsSize; i++)
    {
        sorted_strs[i] = calloc(strlen(strs[i]) + 1, sizeof(char));
        sorting_strs(strs[i], sorted_strs[i]);
        // printf("%s\n", sorted_strs[i]);
    }

    // group by sorted strs
    *returnSize = count_dif(sorted_strs, strsSize, groups_index, index);
    groups = calloc(*returnSize, sizeof(char **));
    returnColumnSizes[0] = calloc(*returnSize, sizeof(int));
    // printf("%i\n", *returnSize);

    for (int i = 0; i < strsSize; i++)
    {
        // printf("groups_index: %i\n", groups_index[i]);
        // printf("index: %i\n", index[i]);
        ++returnColumnSizes[0][groups_index[i] - 1];
    }

    for (int i = 0; i < *returnSize; i++)
    {
        groups[i] = calloc(returnColumnSizes[0][i], sizeof(char *));
    }

    for (int i = 0; i < strsSize; i++)
    {
        groups[groups_index[i] - 1][index[i]] = strs[i];
    }

    return groups;
}
// @lc code=end
