/*
 * @lc app=leetcode id=6296 lang=c
 *
 * [6296] Alternating Digit Sum
 */

// Difficulty:Easy
// You are given a positive integer n. Each digit of n has a sign according to the following rules:

// The most significant digit is assigned a positive sign.
// Each other digit has an opposite sign to its adjacent digits.
// Return the sum of all digits with their corresponding sign.

// @lc code=start

int alternateDigitSum(int n)
{
    int n1 = 0;
    int n2 = 0;
    int count = 0;
    while (n > 0)
    {
        n1 += n % 10;
        n /= 10;
        count++;

        if (n > 0)
        {
            n2 += n % 10;
            n /= 10;
            count++;
        }
    }
    if (count % 2 == 0)
        return n2 - n1;
    return n1 - n2;
}

// @lc code=end
