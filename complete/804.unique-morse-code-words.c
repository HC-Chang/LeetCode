/*
 * @lc app=leetcode id=804 lang=c
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start

char *morse[26] = {".-", "-...", "-.-.", "-..", ".",
                   "..-.", "--.", "....", "..", ".---",
                   "-.-", ".-..", "--", "-.", "---",
                   ".--.", "--.-", ".-.", "...", "-",
                   "..-", "...-", ".--", "-..-", "-.--",
                   "--.."};

typedef struct
{
    int morse_len;
    char *morse_str;
} MORSE_CODE;

typedef struct
{
    int count;
    char **morse_str;
} HASH_TABLE;

void morse_add(MORSE_CODE *m, char *w)
{
    m->morse_len = 0;
    m->morse_str = calloc(48, sizeof(char));
    for (int i = 0; i < strlen(w); i++)
    {
        m->morse_len += strlen(morse[w[i] - 'a']);
        strcat(m->morse_str, morse[w[i] - 'a']);
        m->morse_str[m->morse_len] = '\0';
    }
}

void hash_table_init(HASH_TABLE *h_t)
{
    h_t->count = 0;
    h_t->morse_str = calloc(1, sizeof(char *));
}

void hash_table_add(HASH_TABLE *h_t, char *str)
{
    // check repeat
    for (int i = 0; i < h_t->count; i++)
    {
        if (!strcmp(str, h_t->morse_str[i]))
        {
            return;
        }
    }
    h_t->morse_str = realloc(h_t->morse_str, (h_t->count + 1) * sizeof(char *));
    h_t->morse_str[h_t->count] = str;
    h_t->count++;
}

int uniqueMorseRepresentations(char **words, int wordsSize)
{

    MORSE_CODE *m_c = calloc(wordsSize, sizeof(MORSE_CODE));
    // hash table
    HASH_TABLE *table = calloc(1, sizeof(HASH_TABLE));
    hash_table_init(table);

    for (int i = 0; i < wordsSize; i++)
    {
        morse_add(m_c + i, words[i]);

        // add hash table
        hash_table_add(table, m_c[i].morse_str);
    }

    return table->count;
}
// @lc code=end

// 1 <= words.length <= 100
// 1 <= words[i].length <= 12
// words[i] consists of lowercase English letters.