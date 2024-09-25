/*
 * @lc app=leetcode id=2416 lang=c
 *
 * [2416] Sum of Prefix Scores of Strings
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define ALPHABET_SIZE 26

typedef struct
{
    struct Trie *child[ALPHABET_SIZE];
    int val;
} Trie;

Trie *trieCreate()
{
    Trie *new = malloc(sizeof(Trie));

    new->val = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        new->child[i] = NULL;

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
        ++(obj->val);
    }
}

int trieSearch(Trie *obj, char *word)
{
    int val = 0;
    int index;
    int word_len = strlen(word);
    for (int i = 0; i < word_len; i++)
    {
        index = word[i] - 'a';
        if (!obj->child[index])
            return val;
        obj = obj->child[index];
        val += obj->val;
    }

    return val;
}

void trieFree(Trie *obj)
{
    if (!obj)
        return;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (obj->child[i] != NULL)
            trieFree(obj->child[i]);
    }
    free(obj);
}

int *sumPrefixScores(char **words, int wordsSize, int *returnSize)
{
    Trie *t = trieCreate();

    for (int i = 0; i < wordsSize; i++)
        trieInsert(t, words[i]);

    *returnSize = wordsSize;
    int *ans = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < wordsSize; i++)
        ans[i] = trieSearch(t, words[i]);
    trieFree(t);
    return ans;
}
// @lc code=end

// Note: trie + counting