/*
 * @lc app=leetcode id=2326 lang=cpp
 *
 * [2326] Spiral Matrix IV
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> visited(m, vector<int>(n));

        vector<vector<int>> ans(m, vector<int>(n, -1));
        if (!head)
            return ans;
        ans[0][0] = head->val;
        head = head->next;
        visited[0][0] = 1;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir_idx = 0;
        int pos[2] = {0, 0};
        int next_pos[2];
        while (head)
        {
            while ((pos[0] + dir[dir_idx][0] < 0) || (pos[0] + dir[dir_idx][0] >= m) || (pos[1] + dir[dir_idx][1] < 0) || (pos[1] + dir[dir_idx][1] >= n) ||
                   visited[pos[0] + dir[dir_idx][0]][pos[1] + dir[dir_idx][1]] == 1)
                dir_idx = (dir_idx + 1) % 4;
            pos[0] += dir[dir_idx][0];
            pos[1] += dir[dir_idx][1];

            ans[pos[0]][pos[1]] = head->val;
            visited[pos[0]][pos[1]] = 1;
            head = head->next;
        }
        return ans;
    }
};
// @lc code=end

// Note: array + linked list + matrix