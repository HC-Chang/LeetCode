/*
 * @lc app=leetcode id=2037 lang=c
 *
 * [2037] Minimum Number of Moves to Seat Everyone
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int minMovesToSeat(int *seats, int seatsSize, int *students, int studentsSize)
{
    qsort(seats, seatsSize, sizeof(int), sort);
    qsort(students, studentsSize, sizeof(int), sort);
    int diff = 0;
    for (int i = 0; i < seatsSize; i++)
        diff += abs(seats[i] - students[i]);
    return diff;
}
// @lc code=end

// Note: sorting