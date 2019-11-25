/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_router.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 09:23:56 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 09:17:03 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_router(char *str, t_printf *pf, va_list ap)
{
	char	*tmp;

	if (!(tmp = ft_apply_convert(pf, ap)))
		return (NULL);
	if (!(tmp = ft_apply_flags(tmp, pf)))
		return (NULL);
	if (!(str = ft_strfjoin(tmp, str, 1)))
		return (NULL);
	ft_bzero(&pf->width, sizeof(size_t) * 2);
	return (str);
}