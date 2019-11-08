/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set_width.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/31 11:46:02 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 15:47:35 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_set_accu_width(t_printf *pf, char *str, size_t i)
{
	if (str[i - 1] == '.')
		pf->accu = ft_atoi(str + i);
	else
		if(!(pf->width > 0 && pf->accu == 0))
			pf->width = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

char	*ft_set_width(char *str, t_printf *pf, va_list ap, size_t i)
{
	while (str[i] && !ft_is_option(str[i]))
	{
		while (str[i] == '.')
		{
			if (!ft_char_in_string('.', pf->flags))
				pf->flags[ft_strlen(pf->flags)] = str[i++];
			i++;
		}
		if (str[i] == '*')
		{
			pf->width = va_arg(ap, int);
			if (str[i++ - 1] == '.')
				pf->accu = pf->width;
		}
		else
			i = ft_set_accu_width(pf, str, i);
		if (!ft_is_option(str[i]) && !ft_is_pourcent(str[i]) &&
						!ft_is_flag(str[i]) && !ft_isdigit(str[i]))
		{
			pf->width = 0;
			break ;
		}
	}
	
	return (str + i);
}