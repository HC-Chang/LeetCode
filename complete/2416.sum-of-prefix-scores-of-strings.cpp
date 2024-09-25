/*
 * @lc app=leetcode id=2416 lang=cpp
 *
 * [2416] Sum of Prefix Scores of Strings
 */

// @lc code=start
class Solution
{
public:
    struct TrieNode
    {
        TrieNode *child[26] = {};
        int val;
    };

    void insert_key(TrieNode *&root, string &key)
    {
        TrieNode *curr = root;
        for (char c : key)
        {
            if (curr->child[c - 'a'] == nullptr)
            {
                TrieNode *newNode = new TrieNode();
                curr->child[c - 'a'] = newNode;
            }
            curr = curr->child[c - 'a'];
            ++curr->val;
        }
    }

    int search_key(TrieNode *&root, string &key)
    {
        TrieNode *curr = root;
        int val = 0;
        for (char c : key)
        {
            if (curr->child[c - 'a'] == nullptr)
                return val;
            curr = curr->child[c - 'a'];
            val += curr->val;
        }

        return val;
    }

    vector<int> sumPrefixScores(vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for (string &w : words)
            insert_key(root, w);

        vector<int> scores;
        for (auto w : words)
            scores.push_back(search_key(root, w));
        return scores;
    }
};
// @lc code=end

// Note: trie + counting