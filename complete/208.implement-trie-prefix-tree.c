/*
 * @lc app=leetcode id=208 lang=c
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start

#define ALPHABET_SIZE 26

typedef struct
{
    struct Trie *child[ALPHABET_SIZE];
    bool is_leaf;
} Trie;

Trie *trieCreate()
{
    Trie *new = malloc(sizeof(Trie));

    int i;
    for (i = 0; i < ALPHABET_SIZE; i++)
        new->child[i] = NULL;

    new->is_leaf = false;
    return new;
}

void trieInsert(Trie *obj, char *word)
{
    int index;
    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        index = word[i] - 'a';

        if (!obj->child[index])
            obj->child[index] = trieCreate();

        obj = obj->child[index];
    }

    obj->is_leaf = true;
}

bool trieSearch(Trie *obj, char *word)
{
    int index;

    for (int i = 0; i < strlen(word); i++)
    {
        index = word[i] - 'a';
        if (!obj->child[index])
            return false;

        obj = obj->child[index];
    }

    return (obj != NULL && obj->is_leaf);
}

bool trieStartsWith(Trie *obj, char *prefix)
{
    int index;
    int length = strlen(prefix);
    int i;

    for (i = 0; i < length; i++)
    {
        index = prefix[i] - 'a';

        if (!obj->child[index])
            return false;

        obj = obj->child[index];
    }

    return true;
}

void trieFree(Trie *obj)
{
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);

 * bool param_2 = trieSearch(obj, word);

 * bool param_3 = trieStartsWith(obj, prefix);

 * trieFree(obj);
*/
// @lc code=end
