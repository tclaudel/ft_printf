/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_router.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 09:23:56 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 15:10:32 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_router(char *str, t_printf *pf, va_list ap)
{
	char	*t[2];

	if (!(t[0] = ft_apply_convert(pf, ap)))
		return (NULL);
	if (ft_char_in_string('.', pf->flags) && pf->accu > ft_strlen(t[0]) &&
		ft_char_in_string(pf->option, "diuxX"))
	{
		if (!(t[1] = ft_calloc(sizeof(char), pf->accu - ft_strlen(t[0]) + 1)))
			return (NULL);
		ft_memset(t[1], '0', pf->accu - ft_strlen(t[0]));
		if (!(t[0] = ft_strfjoin(t[1], t[0], 3)))
			return (NULL);
	}
	if (!(t[0] = ft_apply_flags(t[0], pf->flags, pf->width)))
		return (NULL);
	if (!ft_memcmp(t[0], "0", ft_strlen(t[0])) &&
	ft_char_in_string('.', pf->flags))
	{
		ft_strdel(&t[0]);
		t[0] = (ft_calloc(1, 1));
	}
	if (!(str = ft_strfjoin(t[0], str, 1)))
		return (NULL);
	ft_bzero(&pf->width, sizeof(size_t) * 2);
	return (str);
}
