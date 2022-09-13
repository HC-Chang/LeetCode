/*
 * @lc app=leetcode id=393 lang=c
 *
 * [393] UTF-8 Validation
 */

// @lc code=start

bool validUtf8(int *data, int dataSize)
{
    int count = 0;
    for (int i = 0; i < dataSize; i++)
    {
        if (count == 0)
        {
            if ((data[i] >> 5) == 6) // 6 == 0b110
            {
                count = 1;
            }
            else if ((data[i] >> 4) == 14) // 14 == 0b1110
            {
                count = 2;
            }
            else if ((data[i] >> 3) == 30) // 30 == 0b11110
            {
                count = 3;
            }
            else if (data[i] >> 7)
            {
                return false;
            }
        }
        else
        {
            if ((data[i] >> 6) != 2) // 2 == 0b10
            {
                return false;
            }
            count--;
        }
    }

    return count == 0;
}
// @lc code=end
