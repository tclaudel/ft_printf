/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_c_converter.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:31:22 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 17:29:38 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_c_converter(int nb, t_printf *pf)
{
	char *c;

	if (!(c = malloc(sizeof(char) * 2)))
		return (NULL);
	c[0] = nb;
	c[1] = 0;
	if (nb == 0)
	{
		pf->zero = 1;
		pf->current_size++;
	}
	if (pf->width != 0 && nb == 0)
		pf->width -= 1;
	return (c);
}
