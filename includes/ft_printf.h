/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:40:47 by stherkil          #+#    #+#             */
/*   Updated: 2019/08/29 16:17:11 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int					ft_printf(char *s, ...);

typedef struct		s_data
{
	int				nb;
	int				flagno;
	int				flagmin;
	int				flagplu;
	int				flagsp;
	int				flaghas;
	int				flagzer;
	int				iswid;
	int				wid;
	int				isprec;
	int				prec;
	int				ferr;
	int				lenghh;
	int				lengh;
	int				lengl;
	int				lengbigl;
	int				lengll;
}					t_data;
int					getwidt(va_list valist, t_data *arginp, char *s);
int					getprec(va_list valist, t_data *arginp, char *s, int i);
int					getleng(t_data *arginp, char *s);
int					getspeci(va_list valist, t_data *arginp, char *s);
void				applyuoxx(va_list valist, t_data *arginp, char c);
void				applyhash(t_data *arginp);
void				applydi(va_list valist, t_data *arginp);
void				putwidth(t_data *arginp, int maxval, int where);
#endif
