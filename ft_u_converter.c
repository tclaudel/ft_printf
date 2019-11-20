/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_u_converter.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:43:45 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 13:31:31 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_u_converter(unsigned int nb)
{
	char *base;

	base = "0123456789";
	return (ft_itoa_u_base((nb), base));
}
