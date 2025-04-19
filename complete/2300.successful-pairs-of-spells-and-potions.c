/*
 * @lc app=leetcode id=2300 lang=c
 *
 * [2300] Successful Pairs of Spells and Potions

 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int binary_search(int spell, long long success, int *arr, int arr_size)
{
    int left = 0;
    int right = arr_size - 1;
    int middle;
    long long product;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        product = (long long)spell * arr[middle];
        if (product >= success)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return left;
}

int *successfulPairs(int *spells, int spellsSize, int *potions, int potionsSize, long long success, int *returnSize)
{
    *returnSize = spellsSize;
    int *pairs = calloc(spellsSize, sizeof(int));
    qsort(potions, potionsSize, sizeof(int), sort);

    int spell;
    long long product;
    for (int i = 0; i < spellsSize; i++)
    {
        spell = spells[i];
        pairs[i] = potionsSize - binary_search(spell, success, potions, potionsSize);
    }
    return pairs;
}
// @lc code=end
