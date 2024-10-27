/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
// Solution 2:
class Solution
{
private:
    struct TrieNode
    {
        bool isEndOfFolder;
        unordered_map<string, TrieNode *> children;
        TrieNode() : isEndOfFolder(false) {}
    };

    TrieNode *root;

    void deleteTrie(TrieNode *node)
    {
        if (node == nullptr)
            return;
        for (auto &pair : node->children)
        {
            deleteTrie(pair.second);
        }
        delete node;
    }

public:
    Solution() : root(new TrieNode()) {}

    ~Solution() { deleteTrie(root); }

    vector<string> removeSubfolders(vector<string> &folder)
    {
        for (string &path : folder)
        {
            TrieNode *currentNode = root;
            istringstream iss(path);
            string folderName;

            while (getline(iss, folderName, '/'))
            {
                if (folderName.empty())
                    continue;
                if (currentNode->children.find(folderName) ==
                    currentNode->children.end())
                {
                    currentNode->children[folderName] = new TrieNode();
                }
                currentNode = currentNode->children[folderName];
            }
            currentNode->isEndOfFolder = true;
        }

        vector<string> result;
        for (string &path : folder)
        {
            TrieNode *currentNode = root;
            istringstream iss(path);
            string folderName;
            bool isSubFolder = false;

            while (getline(iss, folderName, '/'))
            {
                if (folderName.empty())
                    continue;
                TrieNode *nextNode = currentNode->children[folderName];
                if (nextNode->isEndOfFolder && iss.rdbuf()->in_avail() != 0)
                {
                    isSubFolder = true;
                    break;
                }
                currentNode = nextNode;
            }
            if (!isSubFolder)
                result.push_back(path);
        }

        return result;
    }
};
// @lc code=end

// Note: hash table + trie

// Official Solution

// Solution 1:

// class Solution {
// public:
//     struct TRIE {
//         unordered_map<string, TRIE*> child;
//         bool is_leaf = false;
//     };

//     vector<string> split_slash(string& s) {
//         vector<string> ans;
//         string tmp = "";

//         int n = s.size();
//         for (int i = 0; i <n; i++) {
//             if (s[i] != '/')
//                 tmp += s[i];
//             else {
//                 if (tmp != "")
//                     ans.push_back(tmp);
//                 tmp = "";
//             }
//         }
//         if (tmp != "")
//             ans.push_back(tmp);

//         return ans;
//     }

//     void insert_trie(vector<string> s, TRIE* t) {
//         TRIE* cur = t;
//         int n = s.size();
//         if (cur->is_leaf == true)
//             return;

//         for (int i = 0; i < n; i++) {
//             if (cur->child.find(s[i]) == cur->child.end())
//                 cur->child[s[i]] = new TRIE();

//             cur = cur->child[s[i]];
//             if (i == n - 1)
//                 cur->is_leaf = true;
//         }
//     }

//     void dfs(string& s, TRIE* t, vector<string>& ans) {
//         if (t == nullptr)
//             return;

//         if (t->is_leaf)
//         {
//             ans.push_back(s);
//             return ;
//         }

//         for (auto c : t->child) {
//             s += "/" + c.first;
//             dfs(s, c.second, ans);
//             for (int i = 0; i <= c.first.size(); i++)
//                 s.erase(s.end() - 1);
//         }
//     }

//     vector<string> removeSubfolders(vector<string>& folder) {
//         TRIE* t = new TRIE();
//         string s = "";
//         for (auto f : folder)
//             insert_trie(split_slash(f), t);

//         vector<string> ans;
//         dfs(s, t, ans);

//         return ans;
//     }
// };