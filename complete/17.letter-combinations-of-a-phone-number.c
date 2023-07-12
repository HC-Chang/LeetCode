/*
 * @lc app=leetcode id=17 lang=c
 *
 * [17] Letter arr of a Phone Number
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char phoneMap[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(int index, int digits_size, char *tmp_str, char *str, int *arr_size, char **arr)
{
    if (index == digits_size)
    {
        char *tmp = malloc(sizeof(char) * (digits_size + 1));
        memcpy(tmp, str, sizeof(char) * (digits_size + 1));
        arr[(*arr_size)++] = tmp;
    }
    else
    {
        char digit = tmp_str[index];
        char *letters = phoneMap[digit - '0'];
        int len = strlen(letters);
        for (int i = 0; i < len; i++)
        {
            str[index] = letters[i];
            str[index + 1] = 0;
            backtrack(index + 1, digits_size, tmp_str, str, arr_size, arr);
        }
    }
}

char **letterCombinations(char *digits, int *returnSize)
{
    int digits_size = strlen(digits);
    *returnSize = 0;
    if (digits_size == 0)
        return NULL;

    char *tmp_str = digits;
    int num = 1;
    for (int i = 0; i < digits_size; i++)
        num *= 4;

    char **arr = malloc(sizeof(char *) * num);
    char *str = malloc(sizeof(char *) * digits_size);
    backtrack(0, digits_size, tmp_str, str, returnSize, arr);

    arr = realloc(arr, *returnSize * sizeof(char *));
    free(str);
    return arr;
}
// @lc code=end

// Note: backtracking