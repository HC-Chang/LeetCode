/*
 * @lc app=leetcode id=1855 lang=cpp
 *
 * [1855] Maximum Distance Between a Pair of Values
 */

// @lc code=start
class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (*nums1.rbegin() > *nums2.begin())
            return 0;

        int dis = 0;
        for (int i = 0; i < n1; i++)
        {
            for (int j = i + dis + 1; j < n2; j++)
            {
                if (nums2[j] - nums1[i] >= 0)
                    dis = j - i;
                else
                    break;
            }
        }
        return dis;
    }
};
// @lc code=end

// Note: two pointers, binary search