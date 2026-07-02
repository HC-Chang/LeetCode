/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end());

        struct TrieNode
        {
            vector<string> suggestions;
            TrieNode *children[26];
            TrieNode()
            {
                for (int i = 0; i < 26; ++i)
                    children[i] = nullptr;
            }
        };

        TrieNode *root = new TrieNode();

        for (const string &product : products)
        {
            TrieNode *node = root;
            for (char ch : product)
            {
                int idx = ch - 'a';
                if (!node->children[idx])
                    node->children[idx] = new TrieNode();
                node = node->children[idx];
                if (node->suggestions.size() < 3)
                    node->suggestions.push_back(product);
            }
        }

        vector<vector<string>> result;
        result.reserve(searchWord.size());
        TrieNode *node = root;
        for (char ch : searchWord)
        {
            if (node)
            {
                int idx = ch - 'a';
                node = node->children[idx];
            }
            if (node)
                result.push_back(node->suggestions);
            else
                result.push_back({});
        }

        return result;
    }
};
// @lc code=end

// Note: Trie