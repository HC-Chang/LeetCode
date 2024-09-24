/*
 * @lc app=leetcode id=3043 lang=cpp
 *
 * [3043] Find the Length of the Longest Common Prefix
 */

// @lc code=start
class Solution
{
public:
    struct TrieNode
    {
        TrieNode *child[10];
        bool val_end;

        TrieNode()
        {
            val_end = false;
            for (int i = 0; i < 10; i++)
                child[i] = NULL;
        }
    };

    void insert_key(TrieNode *root, int key)
    {
        TrieNode *curr = root;
        stack<int> s;
        while (key > 0)
        {
            s.push(key % 10);
            key /= 10;
        }

        int tmp;
        while (s.size() > 0)
        {
            tmp = s.top();
            if (curr->child[tmp] == nullptr)
            {
                TrieNode *newNode = new TrieNode();
                curr->child[tmp] = newNode;
            }
            curr = curr->child[tmp];
            s.pop();
        }

        curr->val_end = true;
    }

    int search_key(TrieNode *root, int key)
    {
        TrieNode *curr = root;
        int cnt = 0;

        stack<int> s;
        while (key > 0)
        {
            s.push(key % 10);
            key /= 10;
        }

        int tmp;
        while (s.size() > 0)
        {
            tmp = s.top();
            if (curr->child[tmp] == nullptr)
                return cnt;
            curr = curr->child[tmp];
            cnt++;
            s.pop();
        }

        return cnt;
    }

    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> hash_1;
        unordered_map<int, int> hash_2;
        for (auto val : arr1)
            ++hash_1[val];
        for (auto val : arr2)
            ++hash_2[val];

        TrieNode *root = new TrieNode();
        for (auto h : hash_1)
            insert_key(root, h.first);

        int max_cnt = 0;
        int tmp;
        for (auto h : hash_2)
        {
            tmp = search_key(root, h.first);
            if (tmp > max_cnt)
                max_cnt = tmp;
        }

        return max_cnt;
    }
};
// @lc code=end

// Note: hash table + trie