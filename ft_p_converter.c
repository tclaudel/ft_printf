/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_p_converter.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:39:15 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 13:44:25 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_p_converter(long long address)
{
	char	*s;

	s = ft_itoa_ll_base(address, "0123456789abcdef");
	return (ft_strfjoin("0x", s, 2));
}
