/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_s_converter.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:38:30 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 13:34:18 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_s_converter(char *str, size_t accu, char *flags)
{
	if (!str)
		str = "(null)";
	if (ft_char_in_string('.', flags) && accu < ft_strlen(str))
		return (ft_strndup(str, accu));
	return (ft_strdup(str));
}
