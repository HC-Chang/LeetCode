/*
 * @lc app=leetcode id=1207 lang=c
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
bool uniqueOccurrences(int *arr, int arrSize)
{
    // Solution 2:
    int map1[2001] = {0};
    int map2[1000] = {0};
    for (int i = 0; i < arrSize; i++)
        ++map1[arr[i] + 1000];
    for (int i = 0; i < 2001; i++)
    {
        if (map1[i] == 0)
            continue;
        if (map2[map1[i]] != 0)
            return false;
        ++map2[map1[i]];
    }
    return true;
}
// @lc code=end

// // Solution 1:
// #define SIZE 1000
// int map[SIZE * 2 + 1] = {0};
// for (int i = 0; i < arrSize; i++)
//     ++map[arr[i] + SIZE];
// int map_size = SIZE * 2 + 1;
// for (int i = 0; i < map_size; i++)
// {
//     for (int j = i + 1; j < map_size; j++)
//     {
//         if (map[i] == 0)
//             continue;
//         if (map[i] == map[j])
//             return false;
//     }
// }

// return true;