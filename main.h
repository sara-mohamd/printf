#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 * @width: field width specified
 * @percision: field precision specified
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
*/
typedef struct parameters
{
    unsigned int unsign         : 1;
    unsigned int plus_flag      : 1;
    unsigned int space_flag     : 1;
    unsigned int hashtag_flag   : 1;
    unsigned int zero_flag      : 1;
    unsigned int minus_flag     : 1;
    unsigned int width;
    unsigned int precision;
    unsigned int h_modifier     : 1;
    unsigned int l_modifier     : 1;
} params_t;

/**
 * struct specifier - struct token
 *
 * @specifier: format token
 * @f: the function associated
*/
typedef struct specifier
{
    char *specifier;
    int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c */
int _puts(char *str);
int _putchar(int o);

/* print_functions */
int print_char(va_list var, params_t *myparams);
int print_int(va_list var, params_t *myparams);
int print_string(va_list var, params_t *myparams);
int print_percent(va_list var, params_t *myparams);
int print_S(va_list var, params_t *myparams);

/* number */
char *convert(long int num, int base, int flags, params_t *myparams);
int print_unsigned(va_list var, params_t *myparams);
int print_address(va_list var, params_t *myparams);

/* specifier */
int (*get_specifier(char *s)) (va_list var, params_t *myparams);
int get_print_func(char *s, va_list var, params_t *myparams);
int get_flag(char *s, params_t *myparams);
int get_modifier(char *s, params_t *myparams);
char *get_width(char *s, params_t *myparams, va_list var);

/* convert_number */
int print_hex(va_list var, params_t *myparams);
int print_HEX(va_list var, params_t *myparams);
int print_binary(va_list var, params_t *myparams);
int print_octal(va_list var, params_t *myparams);

/* simple_printers */
int print_from_to(char *initiate, char *stop, char *skip);
int print_rev(va_list var, params_t *myparams);
int print_rot13(va_list var, params_t *myparams);

/* print_number */
int _isdigit(int k);
int _strlen(char *s);
int print_number(char *str, params_t *myparams);
int print_number_right_shift(char *str, params_t *myparams);
int print_number_left_shift(char *str, params_t *myparams);

/* params */
void init_params(params_t *myparams, va_list var);

/* string_fields */
char *get_precision(char *s, params_t *myparams, va_list var);

/* _printf.c */
int _printf(const char *format, ...);

#endif