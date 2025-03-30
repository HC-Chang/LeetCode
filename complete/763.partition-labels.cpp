/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
// Solution 2: hash table + two pointers

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int n =s.size();
            unordered_map<char, int> hash;
            for(int i= 0; i<n ; i++)
                hash[s[i]] = i;
            
            vector<int> ans;
            int l = 0, r = 0;
            for(int i= 0; i<n ; i++)
            {
                r = max(r, hash[s[i]]);
                if( i == r )
                {
                    ans.push_back(r-l+1);
                    l = i+1;
                }
            }
            return ans;
        }   
    };
// @lc code=end

// Note: hash table + two pointers

// Solution 1: hash table + set

// class Solution
// {
// public:
//     vector<int> partitionLabels(string s)
//     {
//         unordered_map<char, int> hash;
//         set<char> my_set;
//         for (auto c : s)
//             ++hash[c];

//         vector<int> ans;
//         int idx = 1;
//         for (auto c : s)
//         {
//             my_set.insert(c);
//             if ((--hash[c]) == 0)
//                 my_set.erase(c);
//             if (my_set.size() == 0)
//             {
//                 ans.push_back(idx);
//                 idx = 0;
//             }
//             idx++;
//         }
//         return ans;
//     }
// };
