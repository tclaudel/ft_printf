/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isdigit.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:42:06 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 09:42:34 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}