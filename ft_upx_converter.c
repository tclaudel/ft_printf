/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_upx_converter.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:48:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 14:07:38 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_upx_converter(unsigned int nb)
{
	char *base;

	base = "0123456789ABCDEF";
	return (ft_itoa_u_base((nb), base));
}
