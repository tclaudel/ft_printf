/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_x_converter.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:47:02 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 18:22:52 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_x_converter(unsigned int nb)
{
	char *base;

	base = "0123456789abcdef";
	return (ft_itoa_u_base((nb), base));
}
