/*
 * @lc app=leetcode id=2011 lang=c
 *
 * [2011] Final Value of Variable After Performing Operations
 */

// @lc code=start
int finalValueAfterOperations(char **operations, int operationsSize)
{
    int val = 0;
    for (int i = 0; i < operationsSize; i++)
    {
        if (!strcmp(operations[i], "++X") || !strcmp(operations[i], "X++"))
            val++;
        else if (!strcmp(operations[i], "--X") || !strcmp(operations[i], "X--"))
            val--;
    }
    return val;
}
// @lc code=end
