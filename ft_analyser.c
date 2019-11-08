/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_analyser.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 11:17:15 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 16:17:52 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_analyser(char *tmp, t_printf *pf, va_list ap)
{
	tmp++;
	pf->option = 0;
	if (!(tmp = ft_new_fmt(tmp, pf)))
		return (NULL);
	tmp = ft_set_width(tmp, pf, ap, 0);
	pf->option = tmp[0];
	if (!(tmp = ft_router(tmp + 1, pf, ap)))
		return (NULL);
	return (tmp);
}
