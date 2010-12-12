/*
 * parser.h - simple parser for shell input
 *
 * This source code is licensed under the MIT License.
 * See the file COPYING for more details.
 *
 * @author: Taku Fukushima <tfukushima@dcl.info.waseda.ac.jp>
 */

#ifndef PSH_TOKENIZER_H_
#define PSH_TOKENIZER_H_

#include <stdbool.h>
#include <sys/types.h>

#define PIPE_MAX  8
#define ELEMENT_MAX  256
#define ARG_MAX  4096
#define INPUT_MAX (4096*4)

typedef enum {
    PIPED_COMMAND,
    COMMAND,
    REDIRECT_IN,
    REDIRECT_IN_APPEND,
    REDIRECT_OUT,
    REDIRECT_OUT_APPEND,
    REDIRECTION,
    REDIRECTION_LIST,
    COMMAND_ELEMENT,
    DIGIT,
    ALPHA,
    ALPHANUM,
    SPECIAL,
    HOME,
    ENV,
    NUM,
    ENV_ASSIGNMENT,
    WORD,
    ERROR,
    END_OF_LINE,
    END_OF_FILE
} token_spec_t;

typedef struct token {
    token_spec_t spec;
    char element[ELEMENT_MAX];
} token_t;

typedef struct tokenizer {
    token_t token;
    char c;
    char input[INPUT_MAX];
} tokenizer_t;

/**
 * init_tokenizer - Initialize and set up scanninig from input.
 * @input: input from prompt
 */
tokenizer_t *init_tokenizer(const char *input);

/**
 * current_token - Get current token.
 * @t: Token information and next character.
 */
const token_t *current_token(tokenizer_t *t);

/**
 * next_token - Scan input and return next token.
 * @t: Token information and next character.
 */
const token_t *next_token(tokenizer_t *t);

/**
 * _next_token - Scan input and return next token.
 * @t: Token information and next character.
 */
const token_t *_next_token(tokenizer_t *t);

#endif  // PSH_TOKENIZER_H_
