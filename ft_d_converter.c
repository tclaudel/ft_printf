/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_d_converter.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:36:18 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/09 17:28:45 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_d_converter(int nb, t_printf *pf)
{
	size_t	size;
	size_t	len;
	char	*tmp;
	char	*str;

	len = 0;
	if (nb < 0)
	{
		if (!(tmp = (char *)ft_calloc(sizeof(char), 2)))
			return (NULL);
		tmp[0] = '-';
		nb = -nb;
		len++;
	}
	else
		tmp = ft_strdup("");
	if (!(str = ft_itoa(nb)))
		return (NULL);
	len += ft_strlen(str);
	size = (pf->width > len ? pf->width - len : 0);
	if (ft_char_in_string('0', pf->flags) &&
	!ft_char_in_string('-', pf->flags) && !ft_char_in_string('.', pf->flags))
		while (size--)
			tmp = ft_strfjoin(tmp, "0", 1);
	return (ft_strfjoin(tmp, str, 3));
}
