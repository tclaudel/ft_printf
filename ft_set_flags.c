/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set_flags.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 13:47:38 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 14:14:35 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_isone_nine(int c)
{
	return (c >= '1' && c <= '9');
}

t_printf	*ft_set_flags(t_printf *pf, char *str)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '%' && !ft_isone_nine(str[i]))
	{
		if (ft_is_flag(str[i]) && !ft_char_in_string(str[i], pf->flags))
		{
			pf->flags[j] = str[i];
			j++;
		}
		i++;
	}
	return (pf);
}

char		*ft_new_fmt(char *old, t_printf *pf)
{
	size_t		i;
	char		*tmp;
	size_t		j;

	j = 0;
	i = 0;
	ft_bzero(pf->flags, 5);
	pf = ft_set_flags(pf, old);
	while (ft_char_in_string(old[j], pf->flags))
		j++;
	if (!(tmp = malloc(sizeof(char) * (ft_strlen(old) - j + 1 + 2))))
		return (NULL);
	j = 0;
	while (old[i])
	{
		if (ft_char_in_string(old[i], "-"))
			i++;
		else
			tmp[j++] = old[i++];
	}
	tmp[j] = 0;
	ft_memcpy(old, tmp, ft_strlen(tmp) + 1);
	ft_strdel(&tmp);
	return (old);
}