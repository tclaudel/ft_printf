/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_p_converter.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:39:15 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 16:39:53 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_p_converter(long long address, t_printf *pf)
{
	char	*s;

	s = ft_itoa_ll_base(address, "0123456789abcdef");
	if (ft_char_in_string('0', pf->flags))
	{
		free(s);
		return (ft_strdup("0x"));
	}
	return (ft_strfjoin("0x", s, 2));
}
