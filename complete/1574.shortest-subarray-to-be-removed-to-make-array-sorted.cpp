/*
 * @lc app=leetcode id=1574 lang=cpp
 *
 * [1574] Shortest Subarray to be Removed to Make Array Sorted
 */

// @lc code=start
class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int right = arr.size() - 1;
        while (right > 0 && arr[right] >= arr[right - 1])
            right--;

        int ans = right;
        int left = 0;
        while (left < right && (left == 0 || arr[left - 1] <= arr[left]))
        {
            while (right < arr.size() && arr[left] > arr[right])
                right++;

            ans = min(ans, right - left - 1);
            left++;
        }
        return ans;
    }
};
// @lc code=end

// Note: two pointers + monotonic stack

// Official Solution