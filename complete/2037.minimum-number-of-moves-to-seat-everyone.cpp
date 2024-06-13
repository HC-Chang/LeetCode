/*
 * @lc app=leetcode id=2037 lang=cpp
 *
 * [2037] Minimum Number of Moves to Seat Everyone
 */

// @lc code=start
class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int diff = 0;
        int n = seats.size();
        for (int i = 0; i < n; i++)
            diff += abs(seats[i] - students[i]);
        return diff;
    }
};
// @lc code=end

// Note: sorting