/*
 * @lc app=leetcode id=605 lang=c
 *
 * [605] Can Place Flowers
 */

// @lc code=start
bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
    for (int i = 0; i < flowerbedSize; ++i)
    {

        if (i - 1 >= 0 && flowerbed[i - 1] == 1)
            continue;
        if (i + 1 < flowerbedSize && flowerbed[i + 1] == 1)
            continue;
        if (flowerbed[i] == 0)
        {
            flowerbed[i] = 1;
            --n;
        }

        if (n <= 0)
            return true;
    }

    return false;
}
// @lc code=end
