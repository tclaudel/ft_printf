/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_c_converter.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:31:22 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 18:22:35 by tclaudel    ###    #+. /#+    ###.fr     */
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
	return (c);
}
