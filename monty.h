monty.h

#ifndef MONTY_H_INCLUDED
#define MONTY_H_INCLUDED

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_file(char *input_file_path);
int parse_line(char *line_content, int line_index, int parsing_format);
void read_file(FILE *file_stream);
int len_chars(FILE *);
void find_func(char *opcode, char *value, int line_index, int parsing_format);

/*Stack operations*/
stack_t *allocate_node(int n);
void release_nodes(void);
void print_stack(stack_t **, unsigned int);
void push_to_stack(stack_t **, unsigned int);
void append_to_queue(stack_t **, unsigned int);

void call_fun(op_func func, char *op, char *val, int line_index, int parsing_format);

void print_top_node(stack_t **, unsigned int);
void pop_top_node(stack_t **, unsigned int);
void nop_op(stack_t **, unsigned int);
void swap_top_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_top_nodes(stack_t **, unsigned int);
void sub_top_nodes(stack_t **, unsigned int);
void div_top_nodes(stack_t **, unsigned int);
void mul_top_nodes(stack_t **, unsigned int);
void mod_top_nodes(stack_t **, unsigned int);

/*String operations*/
void print_char(stack_t **, unsigned int);
void print_strg(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void error(int error_code, ...);
void more_error(int error_code, ...);
void string_error(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif // MONTY_H_INCLUDED
