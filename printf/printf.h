/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 12:32:52 by aschenk           #+#    #+#             */
/*   Updated: 2015/02/07 16:38:53 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/includes/libft.h"
# define ARG(a,b)						((t_args){(a), (b)})
# define SPEC(a,b,c,d,e,f)			((t_spec){(a), (b), (c), (d), (e), (f)})
# define TYPE_D (1)
# define TYPE_S (1<<1)

typedef struct			s_spec {
	int				flags;
	int				width;
	int				precision;
	int				length;
	int				type;
	int				arg_len;
}						t_spec;

typedef struct			s_args {
	char			*arg;
	t_spec			specs;
}						t_args;

#endif
