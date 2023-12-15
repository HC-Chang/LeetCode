/*
 * @lc app=leetcode id=1436 lang=c
 *
 * [1436] Destination City
 */

// @lc code=start
#define SIZE 1000

unsigned long hash(unsigned char *str)
{
    int count = strlen(str);
    unsigned long hash = 5381;
    for (int i = 0; i < count; i++)
        hash = ((hash << 5) + hash) + str[i];

    return hash;
}

char *destCity(char ***paths, int pathsSize, int *pathsColSize)
{
    unsigned long hash_arr[SIZE] = {0};
    int ends[pathsSize];
    for (int i = 0; i < pathsSize; i++)
    {
        ends[i] = hash(paths[i][1]) % SIZE;
        ++hash_arr[hash(paths[i][0]) % SIZE];
        --hash_arr[ends[i]];
    }

    for (int i = 0; i < pathsSize; i++)
    {
        if (hash_arr[ends[i]] == -1)
            return paths[i][1];
    }

    return "";
}
// @lc code=end

// Note: hash table