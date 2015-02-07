/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 13:28:27 by aschenk           #+#    #+#             */
/*   Updated: 2015/02/07 16:56:26 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "printf.h"

int		is_type(char c)
{
	if (c == 'd' || c == 's')
		return (1);
	return (0);
}

char	*get_str_arg(t_args argument, va_list *input)
{
	if ((argument.specs.type & TYPE_D))
		return (ft_itoa(va_arg(*input, int)));
	if ((argument.specs.type & TYPE_S))
		return (va_arg(*input, char *));
}

int		get_type(char **param)
{
	int		type;

	type = 0;
	if (**param == 'd')
		type |= TYPE_D;
	else if (**param == 's')
		type |= TYPE_S;
	*param++;
	return (type);
}

char	*get_argument(char *param, va_list *input, int len)
{
	t_args		argument;
	int			index;

	index = 0;
	argument = ARG(NULL, SPEC(0, 0, 0, 0, 0, 0));
	// if get_* doesn't find anything, returns -1
//	argument.specs.flags = get_flags(&param);
//	argument.specs.width = get_width(&param);
//	argument.specs.precision = get_precision(&param);
//	argument.specs.length = get_length(&param);
	argument.specs.type = get_type(&param);
	argument.arg = get_str_arg(argument, input);
	return (argument.arg);
}

void	print_argument(char **str, va_list *input)
{
	int		itt;

	itt = 0;
	while (!(is_type((*str)[itt++])))
		if ((*str)[itt] == '%')
		{
			ft_putchar('%');
			*str += itt;
			return ;
		}
	ft_putstr(get_argument(*str + 1, input, itt));
	*str += (itt);	
}

void	ft_printf(char *str, ...)
{
	va_list		input;

	va_start(input, str);
	while (str && *str)
	{
		if (*str == '%')
			print_argument(&str, &input);
		ft_putchar(*str);
		str++;
	}
	va_end(input);
}

int		main(int ac, char **av)
{
	ft_printf("%d, %s, %s \n", 1, "hello there!", "ello");
	return (0);
}

