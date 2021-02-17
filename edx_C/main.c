#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WORDS_ALLOCATED_PER_TIME 10
#define MAX_LETTERS_IN_WORD 40

typedef struct {
    char **text;
    uint32_t words;
} text;

void text_init(text *p, uint32_t size)
{
    // Allocating memory for the first 10 words
    p->text = (char**) malloc(size * sizeof(char *));

    // Each word has at most MAX_LETTERS_IN_WORD symbols
    for(uint32_t i = 0; i < size; i++)
        p->text[i] = (char *) calloc(MAX_LETTERS_IN_WORD, sizeof(char));

    p->words = 0;
}

void text_reallocate(text *p)
{
    // Reallocate memory
    p->text = (char **) realloc(p->text, (p->words + WORDS_ALLOCATED_PER_TIME) * sizeof(char *));
    for(uint32_t i = p->words; i < p->words + WORDS_ALLOCATED_PER_TIME; i++)
        p->text[i] = (char *) malloc(MAX_LETTERS_IN_WORD * sizeof(char));
}

void text_read(text *p, FILE *stream)
{
    uint32_t symbols = 0, symbols_in_word = 0;
    char symbol = '\n';
    do {
        if( (symbol = fgetc(stream)) != ' ' && symbol != '\n') {
            if( symbols_in_word < MAX_LETTERS_IN_WORD )
                *(*(p->text + p->words) + symbols_in_word) = symbol;
            symbols_in_word++;
        }
        else {
            symbols_in_word = 0;
            p->words++;
            if( p->words % WORDS_ALLOCATED_PER_TIME == 0 && p->words != 0 ) {
                text_reallocate(p);
            }
        }
        symbols++;
    } while( symbol != '\n' && symbols < UINT32_MAX);
}

void text_print(text *p)
{
    for(uint32_t i = 0; i < p->words; i++)
        printf("%s\n", *(p->text + i));
}

void text_reverse(text *in, text *out)
{
    uint32_t words = in->words;
    text_init(out, words);
    out->words = words;
    for(uint32_t i = 0; i < words; i++)
        strcpy(out->text[i], in->text[words - i - 1]);
}

void text_print_whole(text *p)
{
    for(uint32_t i = 0; i < p->words; i++) {
        printf("%s", *(p->text + i));
        printf(" ");
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    text txt, txt_copy;

    text_init(&txt, WORDS_ALLOCATED_PER_TIME);
    text_read(&txt, stdin);
    text_print(&txt);

    text_reverse(&txt, &txt_copy);
    text_print_whole(&txt_copy);

    return 0;
}