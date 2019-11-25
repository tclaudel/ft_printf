/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_d_converter.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 09:23:31 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 09:22:42 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_d_converter(int nb, t_printf *pf)
{
	return (ft_itoa_pf(nb, pf));
}
