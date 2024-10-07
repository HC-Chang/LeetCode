/*
 * @lc app=leetcode id=2696 lang=cpp
 *
 * [2696] Minimum String Length After Removing Substrings
 */

// @lc code=start
// Solution 2:
class Solution
{
public:
    int minLength(string s)
    {
        stack<char> st;
        int n = s.size();
        for (auto ss : s)
        {
            if (!st.empty() && ((st.top() == 'A' && ss == 'B') || (st.top() == 'C' && ss == 'D')))
                st.pop();
            else
                st.push(ss);
        }
        return st.size();
    }
};
// @lc code=end

// Note: stack

// Solution 1:

// class Solution
// {
// public:
//     void erase_ABCD(int idx_1, int idx_2, string &s)
//     {
//         int pre = min(idx_1, idx_2);
//         int post = max(idx_1, idx_2);
//         if (post != -1)
//             s.erase(post, 2);
//         if (pre != -1)
//             s.erase(pre, 2);
//     }

//     int minLength(string s)
//     {
//         int idx_1 = -1;
//         int idx_2 = -1;
//         while (1)
//         {
//             idx_1 = -1;
//             idx_2 = -1;

//             idx_1 = s.find("AB");
//             idx_2 = s.find("CD");
//             if (idx_1 == -1 && idx_1 == idx_2)
//                 break;

//             erase_ABCD(idx_1, idx_2, s);
//         }
//         return s.size();
//     }
// };