/*
 * @lc app=leetcode id=201 lang=c
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start

int rangeBitwiseAnd(int left, int right)
{
    // Solution 1:
    // unsigned int val = 0;
    // for (int i = 30; i >= 0; i--)
    // {
    //     if ((left & (1 << i)) == (right & (1 << i)))
    //     {
    //         val += (left & (1 << i));
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }

    // return (unsigned int)val;



    // Solution 2:
    int count = 0;
    while (left != right)
    {
        left = left >> 1;
        right = right >> 1;
        count++;
    }

    return left << count;
}
// @lc code=end

// Note: bit manipulation

// 從最高 bit 數檢查
// 如有一樣則相加
// 有異則停止