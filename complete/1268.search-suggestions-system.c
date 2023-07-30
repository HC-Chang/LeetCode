/*
 * @lc app=leetcode id=1268 lang=c
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int sort(const void *a, const void *b)
{
    char *x = ((char **)a)[0];
    char *y = ((char **)b)[0];
    return strcmp(x, y);
}

char ***suggestedProducts(char **products, int productsSize, char *searchWord, int *returnSize, int **returnColumnSizes)
{
    int len = strlen(searchWord);
    char ***ans = malloc(sizeof(char **) * len);
    returnColumnSizes[0] = malloc(sizeof(int) * len);
    *returnSize = len;

    qsort(products, productsSize, sizeof(char *), sort);

    int startIndex = 0;
    int cnt;
    for (int i = 0; i < len; i++)
    {
        char **lists = malloc(sizeof(char *) * 3);
        ans[i] = lists;
        cnt = 0;
        for (int j = startIndex; j < productsSize; j++)
        {
            int ret = strncmp(searchWord, products[j], i + 1);
            if (ret == 0)
            {
                if (cnt == 0)
                    startIndex = j;

                lists[cnt] = malloc(strlen(products[j]) + 1);
                strcpy(lists[cnt], products[j]);
                cnt++;
                if (cnt == 3)
                    break;
            }
            else if (ret < 0)
                break;
            else
                continue;
        }
        returnColumnSizes[0][i] = cnt;
    }

    return ans;
}
// @lc code=end

// Note: Trie