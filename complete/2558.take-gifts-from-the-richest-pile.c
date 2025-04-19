/*
 * @lc app=leetcode id=2558 lang=c
 *
 * [2558] Take Gifts From the Richest Pile
 */

// Difficulty:Easy

// You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

// Choose the pile with the maximum number of gifts.
// If there is more than one pile with the maximum number of gifts, choose any.
// Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
// Return the number of gifts remaining after k seconds.

// Constraints:
// 1 <= gifts.length <= 103
// 1 <= gifts[i] <= 109
// 1 <= k <= 103

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)b - *(int *)a; }

long long pickGifts(int *gifts, int giftsSize, int k)
{
    for (int i = 0; i < k; i++)
    {
        qsort(gifts, giftsSize, sizeof(int), sort);
        gifts[0] = sqrt(gifts[0]);
    }

    long long r = 0;
    for (int i = 0; i < giftsSize; i++)
        r += gifts[i];
    return r;
}

// @lc code=end