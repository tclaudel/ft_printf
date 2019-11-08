/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_char_in_string.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 14:29:53 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 09:42:14 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_char_in_string(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}
