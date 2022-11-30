/*
 * @lc app=leetcode id=1207 lang=c
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
#define SIZE 1000
bool uniqueOccurrences(int *arr, int arrSize)
{
    int map[SIZE * 2 + 1] = {0};
    for (int i = 0; i < arrSize; i++)
        ++map[arr[i] + SIZE];
    int map_size = SIZE * 2 + 1;
    for (int i = 0; i < map_size; i++)
    {
        for (int j = i + 1; j < map_size; j++)
        {
            if (map[i] == 0)
                continue;
            if (map[i] == map[j])
                return false;
        }
    }

    return true;
}
// @lc code=end
