/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_router.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 09:23:56 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 18:22:47 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_router(char *str, t_printf *pf, va_list ap)
{
	char	*tmp;
	char	*s;
	size_t	lstr;

	if (!(tmp = ft_apply_convert(pf, ap)))
		return (NULL);
	if (!(tmp = ft_apply_flags(tmp, pf)))
		return (NULL);
	pf->current_size = ft_strlen(tmp) > pf->current_size ?
	ft_strlen(tmp) : pf->current_size;
	lstr = (ft_strlen(str));
	if (!(s = ft_memjoin(tmp, str, pf->current_size, lstr)))
		return (NULL);
	ft_strdel(&tmp);
	pf->current_size += lstr;
	ft_bzero(&pf->width, sizeof(size_t) * 2);
	return (s);
}
