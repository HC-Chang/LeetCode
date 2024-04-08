/*
 * @lc app=leetcode id=1700 lang=cpp
 *
 * [1700] Number of Students Unable to Eat Lunch
 */

// @lc code=start
// Solution 2:
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();
        queue<int> q;
        for (auto s : students)
            q.push(s);

        int cnt = 0;
        int i = 0;
        while (q.size() > 0 && cnt != q.size())
        {
            if (q.front() == sandwiches[i])
            {
                i++;
                cnt = 0;
            }
            else
            {
                q.push(q.front());
                cnt++;
            }
            q.pop();
        }
        return q.size();
    }
};
// @lc code=end

// Note: queue

// Solution 1:
// class Solution {
// public:
//     int countStudents(vector<int>& students, vector<int>& sandwiches) {
//         int cnt[2] = {0};
//         int n = students.size();
//         for (int i = 0; i < n; i++)
//             ++cnt[students[i]];
//         vector<int> visited(n);
//         int student_idx = 0;
//         int sandwitch_idx = 0;
//         while (sandwitch_idx < n && cnt[sandwiches[sandwitch_idx]] > 0)
//         {
//             if (visited[student_idx] == 0 && students[student_idx] == sandwiches[sandwitch_idx])
//             {
//                 visited[student_idx] = 1;
//                 sandwitch_idx++;
//                 --cnt[students[student_idx]];
//             }

//             student_idx = (student_idx + 1) % n;
//         }
//         return n - sandwitch_idx;
//     }
// };