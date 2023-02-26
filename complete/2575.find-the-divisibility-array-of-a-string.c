/*
 * @lc app=leetcode id=2575 lang=c
 *
 * [2575] Find the Divisibility Array of a String
 */

// Difficulty:Medium

// You are given a 0-indexed string word of length n consisting of digits, and a positive integer m.

// The divisibility array div of word is an integer array of length n such that:

// div[i] = 1 if the numeric value of word[0,...,i] is divisible by m, or
// div[i] = 0 otherwise.
// Return the divisibility array of word.

// Constraints:
// 1 <= n <= 100000
// word.length == n
// word consists of digits from 0 to 9
// 1 <= m <= 1000000000

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *divisibilityArray(char *word, int m, int *returnSize)
{
    int n = strlen(word);
    *returnSize = n;
    int *r = calloc(n, sizeof(int));
    long long sum = 0;
    char *str = calloc(n + 1, sizeof(char));
    for (int i = 0; i < n; i++)
    {
        strncpy(str, word + i, 1);
        sum = sum * 10 + (long long)atoi(str);
        sum %= m;
        if (sum == 0)
            r[i] = 1;
        else
            r[i] = 0;
    }
    free(str);
    return r;
}
// @lc code=end