#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @myparams: the parameters struct
 * @var: the argument pointer
 *
 * Return: void
 */
void init_params(params_t *myparams, va_list var)
{
	myparams->unsign = 0;

	myparams->plus_flag = 0;
	myparams->space_flag = 0;
	myparams->hashtag_flag = 0;
	myparams->zero_flag = 0;
	myparams->minus_flag = 0;

	myparams->width = 0;
	myparams->precision = UINT_MAX;

	myparams->h_modifier = 0;
	myparams->l_modifier = 0;
	(void)var;
}
