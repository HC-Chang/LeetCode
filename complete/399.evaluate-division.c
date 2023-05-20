/*
 * @lc app=leetcode id=399 lang=c
 *
 * [399] Evaluate Division
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double math(int k, double op1, double op2)
{
    switch (k)
    {
    case 1:
        op1 = 1.0;
        break;
    case 2:
        op1 = op2;
        break;
    case 3:
        op1 = 1 / op2;
        break;
    case 4:
    case 5:
        op1 = op1 * op2;
        break;
    case 6:
    case 7:
        op1 = op1 / op2;
        break;
    }
    return op1;
}

int match(char **strs, char *fm, char *fz)
{
    int x00 = !strcmp(fm, strs[0]);
    int x01 = !strcmp(fm, strs[1]);
    int x10 = !strcmp(fz, strs[0]);
    int x11 = !strcmp(fz, strs[1]);

    int k = 0;
    if ((!x00 && !x01 && !x10 && !x11) ||
        (x00 && x01 && !x10) ||
        (x10 && x11 && !x00))
        k = 0; // no match or useless match
    else if ((x00 && x10) || (x01 && x11))
        k = 1; // 1
    else if (x00 && x11)
        k = 2; // equal
    else if (x01 && x10)
        k = 3; // reverse
    else if (x00)
        k = 4; // multiply
    else if (x11)
        k = 5;
    else if (x01)
        k = 6; // divide
    else if (x10)
        k = 7;
    return k;
}

int calculate(int *visited, double *d, char ***equa, double *val, int rowsz, char *fm, char *fz)
{
    int k, x;
    for (int i = 0; i < rowsz; i++)
    {
        if (visited[i] == 0)
        {
            k = match(equa[i], fm, fz);
            if (k >= 1 && k <= 3)
            {
                *d = math(k, *d, val[i]);
                return 1;
            }
            else if (k != 0)
            {
                visited[i] = 1;
                if (k == 4)
                    x = calculate(visited, d, equa, val, rowsz, equa[i][1], fz);
                else if (k == 5)
                    x = calculate(visited, d, equa, val, rowsz, fm, equa[i][0]);
                else if (k == 6)
                    x = calculate(visited, d, equa, val, rowsz, equa[i][0], fz);
                else
                    x = calculate(visited, d, equa, val, rowsz, fm, equa[i][1]);
                visited[i] = 0;
                if (x)
                {
                    *d = math(k, *d, val[i]);
                    return 1;
                }
            }
        }
    }
    return 0;
}
double *calcEquation(char ***equations, int equationsRowSize, int equationsColSize, double *values, int valuesSize, char ***queries, int queriesRowSize, int queriesColSize, int *returnSize)
{
    int *visited = calloc(equationsRowSize, sizeof(int));
    double *results = malloc(queriesRowSize * sizeof(double));

    *returnSize = queriesRowSize;
    double d;
    for (int i = 0; i < queriesRowSize; i++)
    {
        d = -1.0;
        calculate(visited, &d, equations, values, equationsRowSize, queries[i][0], queries[i][1]);
        results[i] = d;
    }

    free(visited);
    return results;
}

// @lc code=end
