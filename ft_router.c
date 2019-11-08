/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_router.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 14:32:10 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 16:41:47 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_router(char *str, t_printf *pf, va_list ap)
{
	char	*tmp;
	char	*tmp2;
	size_t	lmalloc;
	
	if (!(tmp = ft_apply_convert(pf, ap)))
		return (NULL);
	dprintf(1, "tmp :\t%s\n", tmp);
	if (ft_char_in_string('.', pf->flags) && pf->accu > ft_strlen(tmp) &&
		ft_char_in_string(pf->option, "diuxX"))
	{
		lmalloc = pf->accu - ft_strlen(tmp);
		if (!(tmp2 = malloc(sizeof(char) * lmalloc + 1)))
			return (NULL);
		ft_memset(tmp2, '0', lmalloc);
		tmp2[lmalloc] = 0;
		if (!(tmp = ft_strfjoin(tmp2, tmp, 3)))
			return (NULL);
	}
	if (!(tmp = ft_apply_flags(tmp, pf->flags, pf->width)))
		return (NULL);
	if (!ft_memcmp(tmp, "0", ft_strlen(tmp)))
		tmp = (ft_calloc(1, 1));
	if (!(str = ft_strfjoin(tmp, str, 1)))
		return (NULL);
	ft_bzero(&pf->width, sizeof(size_t) * 2);
	return (str);
}
