/*
 * @lc app=leetcode id=2785 lang=c
 *
 * [2785] Sort Vowels in a String
 */

// @lc code=start
int sort(void *a, void *b) { return *(char *)a - *(char *)b; }
char *sortVowels(char *s)
{
    int n = strlen(s);
    char arr[n];
    int index[n];
    int arr_size = 0;
    memset(arr, 0, sizeof(arr));
    memset(index, 0, sizeof(index));
    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            index[arr_size] = i;
            arr[arr_size++] = s[i];
            break;
        }
    }

    qsort(arr, arr_size, sizeof(char), sort);
    for (int i = 0; i < arr_size; i++)
        s[index[i]] = arr[i];
    return s;
}
// @lc code=end

// Note: sorting