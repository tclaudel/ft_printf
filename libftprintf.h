/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:06:37 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 14:07:04 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./Libft/libft.h"

typedef struct		s_printf
{
	char		flags[5];
	char		option;
	size_t		width;
	size_t		accu;
	size_t		return_size;
}					t_printf;

int		ft_printf(const char *incstr, ...);

//		<== CONVERTERS ==>

char				*ft_c_converter(int nb, t_printf *pf);
char				*ft_d_converter(int nb);
char				*ft_i_converter(int nb);
char				*ft_s_converter(char *str, size_t width, char *flags);
char				*ft_p_converter(long long address);/*, char *flags, size_t accu)*/
char				*ft_u_converter(unsigned int nb);
char				*ft_x_converter(unsigned int nb);
char				*ft_upx_converter(unsigned int nb);
char				*ft_pourcent_converter(void);

//		<== DETECTORS ==>

int					ft_is_pourcent(char c);
int					ft_is_flag(char c);
int					ft_is_option(char c);

//		<== ANALYSER ==>

char				*ft_analyser(char *tmp, t_printf *pf, va_list ap);
t_printf			*ft_set_flags(t_printf *pf, char *str);
char				*ft_new_fmt(char *old, t_printf *pf);
char				*ft_set_width(char *str, t_printf *pf, va_list ap, size_t i);

//		<== ROUTER ==>

char				*ft_router(char *str, t_printf *pf, va_list ap);
char				*ft_apply_flags(char *str, char *flags, size_t width);
char				*ft_apply_convert(t_printf *pf, va_list ap);

#endif