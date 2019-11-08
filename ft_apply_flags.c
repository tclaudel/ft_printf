/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_apply_flags.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 14:30:58 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 16:21:04 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_apply_flags(char *str, char *flags, size_t width)
{
	size_t	lmalloc;
	size_t	lenstr;
	char	*tmp;

	lenstr = ft_strlen(str);
	lmalloc = (width > lenstr ? width - lenstr : 0);
	if (!(tmp = ft_calloc(sizeof(char), lmalloc + 1)))
		return (NULL);
	if (ft_char_in_string('0', flags) && !ft_char_in_string('-', flags) &&
		!ft_char_in_string('.', flags))
		ft_memset(tmp, '0', lmalloc);
	else
		ft_memset(tmp, ' ', lmalloc);
	if (!ft_char_in_string('-', flags))
		str = ft_strfjoin(tmp, str, 3);
	else
		str = ft_strfjoin(str, tmp, 3);
	flags = NULL;
	return (str);
}
