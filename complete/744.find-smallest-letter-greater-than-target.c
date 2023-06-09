/*
 * @lc app=leetcode id=744 lang=c
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
char binary_search(char *arr, int arrSize, char target)
{
    int left = 0;
    int right = arrSize - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] >= target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    while (arr[left] == target)
        left++;
    return arr[left];
}

char nextGreatestLetter(char *letters, int lettersSize, char target)
{
    if (target >= letters[lettersSize - 1])
        return letters[0];
    return binary_search(letters, lettersSize, target);
}
// @lc code=end
