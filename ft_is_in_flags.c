/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_in_flags.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 09:47:27 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 13:27:59 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_is_in_flags(char c, t_printf *pf)
{
	return (ft_char_in_string(c, pf->flags));
}
