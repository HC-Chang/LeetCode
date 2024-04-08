/*
 * @lc app=leetcode id=1700 lang=c
 *
 * [1700] Number of Students Unable to Eat Lunch
 */

// @lc code=start
int countStudents(int *students, int studentsSize, int *sandwiches, int sandwichesSize)
{
    int cnt[2] = {0};
    for (int i = 0; i < studentsSize; i++)
        ++cnt[students[i]];
    int visited[studentsSize];
    memset(visited, 0, sizeof(visited));
    int student_idx = 0;
    int sandwitch_idx = 0;
    while (sandwitch_idx < sandwichesSize && cnt[sandwiches[sandwitch_idx]] > 0)
    {
        if (visited[student_idx] == 0 && students[student_idx] == sandwiches[sandwitch_idx])
        {
            visited[student_idx] = 1;
            sandwitch_idx++;
            --cnt[students[student_idx]];
        }

        student_idx = (student_idx + 1) % studentsSize;
    }
    return sandwichesSize - sandwitch_idx;
}
// @lc code=end

// Note: queue