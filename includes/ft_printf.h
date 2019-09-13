/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:40:47 by stherkil          #+#    #+#             */
/*   Updated: 2019/09/13 15:25:01 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int					ft_printf(char *s, ...);

typedef struct		s_data
{
	int						nb;
	int						flagmin;
	int						flagplu;
	int						flagsp;
	int						flaghas;
	int						flagzer;
	int						flagzerf;
	int						flagzer_;
	int						iswid;
	int						wid;
	int						isprec;
	int						prec;
	int						ferr;
	int						lenghh;
	int						lengh;
	int						lengl;
	int						lengbigl;
	int						lengll;
	int						canprint;
	int						totallen;
	int						len;
}					t_data;
int					getwidt(va_list valist, t_data *arginp, char *s);
int					getprec(va_list valist, t_data *arginp, char *s, int i);
int					getleng(t_data *arginp, char *s);
int					haveflags(t_data *arginp);
int					applyf(va_list valist, t_data *arginp,
long double inp, long long int inpi);
void				applycps(va_list valist, char c, t_data *arginp, int len);
int					getspeci(va_list valist, t_data *arginp, char *s);
void				putwidth(t_data *arginp, int maxval, int where);
int					ifzero(t_data *arginp, long double inp, long long int inpi);
intmax_t			get_signed(va_list valist, t_data *arginp);
uintmax_t			get_unsigned(va_list valist, t_data *arginp);
#endif
