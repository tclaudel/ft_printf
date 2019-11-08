/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pourcent_converter.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/01 09:36:30 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 10:38:39 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_pourcent_converter(void)
{
	char *c;

	if (!(c = malloc(sizeof(char) * 2)))
		return (NULL);
	c[0] = '%';
	c[1] = 0;
	return (c);
}
