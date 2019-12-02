/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_d_converter.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 09:23:31 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 18:22:32 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_d_converter(int nb, t_printf *pf)
{
	return (ft_itoa_pf(nb, pf));
}
