/*
 * @lc app=leetcode id=211 lang=c
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start

#define ALPHABET_SIZE 26

typedef struct
{
    struct WordDictionary *child[ALPHABET_SIZE];
    bool is_leaf;
} WordDictionary;

WordDictionary *wordDictionaryCreate()
{
    WordDictionary *new = malloc(sizeof(WordDictionary));

    for (int i = 0; i < ALPHABET_SIZE; i++)
        new->child[i] = NULL;

    new->is_leaf = false;
    return new;
}

void wordDictionaryAddWord(WordDictionary *obj, char *word)
{
    int index;
    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        index = word[i] - 'a';

        if (!obj->child[index])
            obj->child[index] = wordDictionaryCreate();

        obj = obj->child[index];
    }

    obj->is_leaf = true;
}

bool wordDictionarySearch(WordDictionary *obj, char *word)
{
    char *cur = word;
    int index;
    while (*cur)
    {
        if (*cur == '.')
        {
            cur++;
            for (int x = 0; x < ALPHABET_SIZE; x++)
            {
                if (obj->child[x] && wordDictionarySearch(obj->child[x], cur))
                    return true;
            }
            return false;
        }

        index = *cur - 'a';
        if (!obj->child[index])
            return false;
        obj = obj->child[index];
        cur++;
    }

    return obj->is_leaf;
}

void wordDictionaryFree(WordDictionary *obj)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        free(obj->child[i]);
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);

 * bool param_2 = wordDictionarySearch(obj, word);

 * wordDictionaryFree(obj);
*/
// @lc code=end
