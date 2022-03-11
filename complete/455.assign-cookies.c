/*
 * @lc app=leetcode id=455 lang=c
 *
 * [455] Assign Cookies
 */

// @lc code=start

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}
void quick_sort(int arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}


int findContentChildren(int *g, int gSize, int *s, int sSize)
{
    quick_sort(g,gSize);
    quick_sort(s,sSize);
    int count = 0;
    int g_index = 0;
    int s_index = 0;
    
    while (g_index < gSize && s_index < sSize)
    {
        if(g[g_index] <= s[s_index])
        {
            count ++;
            g_index++;
            s_index++;
        }
        else
        {
            s_index ++;
        }
    }
    

    return count;
}
// @lc code=end
