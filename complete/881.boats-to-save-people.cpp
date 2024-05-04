/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int boat_count = 0;
        while (left <= right)
        {
            if (people[left] + people[right] <= limit)
            {
                left++;
                right--;
            }
            else
                right--;
            boat_count++;
        }
        return boat_count;
    }
};
// @lc code=end

// Note: sorting + two pointers