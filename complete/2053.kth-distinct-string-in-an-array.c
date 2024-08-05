/*
 * @lc app=leetcode id=2053 lang=c
 *
 * [2053] Kth Distinct String in an Array
 */

// @lc code=start
unsigned long hash(unsigned char *str, int count)
{
    unsigned long hash = 5381;
    for (int i = 0; i < count; i++)
        hash = ((hash << 5) + hash) + str[i];

    return hash;
}

char *kthDistinct(char **arr, int arrSize, int k)
{
    int SIZE = arrSize + 5000000;
    int hash_arr[SIZE];
    memset(hash_arr, 0, sizeof(hash_arr));

    for (int i = 0; i < arrSize; i++)
        ++hash_arr[(int)(hash(arr[i], strlen(arr[i])) % SIZE)];

    for (int i = 0; i < arrSize; i++)
    {
        if (hash_arr[(int)(hash(arr[i], strlen(arr[i])) % SIZE)] == 1)
            k--;
        if (k == 0)
            return arr[i];
    }
    return "";
}
// @lc code=end

// Note: hash table + counting