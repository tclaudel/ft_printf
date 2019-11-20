/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_apply_flags.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 14:30:58 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 11:28:13 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_int_accu(char **str, t_printf *pf)
{
	char	*zero;

	if (!ft_memcmp(*str, "0", ft_strlen(*str)) && pf->accu == 0)
	{
		ft_strdel(str);
		*str = ft_calloc(sizeof(char), 1);
	}
	if (pf->accu > ft_strlen(*str))
	{
		if (!(zero = ft_calloc(sizeof(char), pf->accu - ft_strlen(*str) + 1)))
			return (NULL);
		ft_memset(zero, '0', pf->accu - ft_strlen(*str));
	}
	else
		zero = ft_calloc(sizeof(char), 1);
	return (zero);
}

char	*ft_negative_flag(char *str, char *tmp, t_printf *pf)
{
	dprintf(1, "str\t: |%s|\ntmp\t: |%s|\n", str, tmp);
	if (!ft_char_in_string('-', pf->flags))
		str = ft_strfjoin(tmp, str, 3);
	else
		str = ft_strfjoin(str, tmp, 3);
	
	return (str);
}

char	*ft_zero_flag(char *str, t_printf *pf, char sign)
{
	size_t	lmalloc;
	size_t	lenstr;
	char	*tmp;

	lenstr = ft_strlen(str);
	lmalloc = (pf->width > lenstr ? pf->width - lenstr + sign : 0);
	if (!(tmp = ft_calloc(sizeof(char), lmalloc + 1)))
		return (NULL);
	if (ft_char_in_string('0', pf->flags))
		ft_memset(tmp, '0', lmalloc);
	else
		ft_memset(tmp, ' ', lmalloc);
	return (tmp);
}

char	*ft_del_neg(char *str)
{
	char		*tmp;
	size_t		j;
	size_t		i;

	j = 0;
	i = 0;
	while (ft_char_in_string(str[j], "-"))
		j++;
	if (!(tmp = malloc(sizeof(char) * (ft_strlen(str) - j + 1 + 2))))
		return (NULL);
	j = 0;
	while (str[i])
	{
		if (ft_char_in_string(str[i], "-"))
			i++;
		else
			tmp[j++] = str[i++];
	}
	tmp[j] = 0;
	ft_memcpy(str, tmp, ft_strlen(tmp) + 1);
	ft_strdel(&tmp);
	return (str);
}

char	*ft_apply_flags(char *str, t_printf *pf)
{
	char	*tmp;
	char	sign;

	sign = (str[0] == '-' && ft_is_in_flags('.', pf));
	if (sign && ft_is_in_flags('0',pf))
		ft_del_neg(str);
	if (pf->width + 1 > ft_strlen(str))
		pf->width -= sign;
	if (ft_char_in_string('.', pf->flags) &&
	ft_char_in_string(pf->option, "diuxX")
	&& pf->accu != 0 && !(ft_is_in_flags('*', pf) && ft_is_in_flags('-', pf)))
		tmp = ft_int_accu(&str, pf);
	else
		tmp = ft_zero_flag(str, pf,sign);
	str = ft_negative_flag(str, tmp, pf);
	dprintf(1, "str\t: %s\n",str);
	if (sign && ft_is_in_flags('0',pf))
		str = ft_strfjoin("-", str, 2);
	ft_bzero(pf->flags, 5);
	return (str);
}
