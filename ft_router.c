/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_router.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 09:23:56 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 17:49:58 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

// #include "libftprintf.h"

// char	*ft_router(char *str, t_printf *pf, va_list ap)
// {
// 	char	*tmp;

// 	if (!(tmp = ft_apply_convert(pf, ap)))
// 		return (NULL);
// 	if (!(tmp = ft_apply_flags(tmp, pf)))
// 		return (NULL);
// 	pf->current_size = ft_strlen(tmp) + pf->zero + ft_strlen(str);
// 	if (!(str = ft_memjoin(tmp, str, ft_strlen(tmp) + pf->zero, ft_strlen(str))))
// 		return (NULL);
// 	ft_bzero(&pf->width, sizeof(size_t) * 2);
// 	dprintf(1, "str\t: %c%s\n", str[0], str + 1);
// 	return (str);
// }

#include "libftprintf.h"

char	*ft_router(char *str, t_printf *pf, va_list ap)
{
	char	*tmp;
	size_t	lstr;

	// dprintf(1, "str\t: %s\n", str);
	if (!(tmp = ft_apply_convert(pf, ap)))
		return (NULL);
	if (!(tmp = ft_apply_flags(tmp, pf)))
		return (NULL);
	pf->current_size = ft_strlen(tmp) > pf->current_size ? ft_strlen(tmp) : pf->current_size;
	lstr = (ft_strlen(str));
	if (!(str = ft_memjoin(tmp, str, pf->current_size + pf->zero, lstr + 1)))
		return (NULL);
	// dprintf(1, "router :|%c%s|\n", str[0], str +1);
	pf->current_size += lstr + pf->zero;
	// dprintf(1, "size\t:%zu\n", pf->current_size);
	ft_bzero(&pf->width, sizeof(size_t) * 2);
	return (str);
}