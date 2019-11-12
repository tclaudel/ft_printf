/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_d_converter.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 09:23:31 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 11:22:41 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_d_converter(int nb, t_printf *pf, size_t u, size_t len)
{
	size_t			size;
	char			*tmp;
	char			*str;

	u = nb;
	if (nb < 0)
	{
		if (!(tmp = (char *)ft_calloc(sizeof(char), 2)))
			return (NULL);
		tmp[0] = '-';
		u = -u;
		len++;
	}
	else
		tmp = ft_strdup("");
	if (!(str = ft_itoa_u_base(u, "0123456789")))
		return (NULL);
	len += ft_strlen(str);
	size = (pf->width > len ? pf->width - len : 0);
	if (ft_char_in_string('0', pf->flags) &&
	!ft_char_in_string('-', pf->flags) && !ft_char_in_string('.', pf->flags))
		while (size--)
			tmp = ft_strfjoin(tmp, "0", 1);
	return (ft_strfjoin(tmp, str, 3));
}
