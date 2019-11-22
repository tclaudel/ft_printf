/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_apply_flags.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 14:30:58 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 16:50:59 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

// char	*ft_int_accu(char *str, t_printf *pf, int *sign)
// {
// 	char	*zero;

// 	// dprintf(1, "sign\t: %c\n", *sign + '0');
// 	// dprintf(1, "str\t: %s\n", str);
// 	if (!ft_memcmp(str, "0", ft_strlen(str)) && pf->accu == 0)
// 	{
// 		ft_strdel(&str);
// 		str = ft_calloc(sizeof(char), 1);
// 	}
// 	if (pf->accu > ft_strlen(str))
// 	{
// 		if (!(zero = ft_calloc(sizeof(char), pf->accu - ft_strlen(str) + 1)))
// 			return (NULL);
// 		ft_memset(zero, '0', pf->accu - ft_strlen(str));
// 	}
// 	else
// 		zero = ft_calloc(sizeof(char), 1);
// 	// dprintf(1, "zero\t: |%s|\n", zero);
// 	if (pf->width >= pf->accu)
// 		zero = ft_width_accu(zero, pf, sign, str);
// 	//dprintf(1, "zero\t: |%s|\n", zero);
// 	return (zero);
// }

// char	*ft_width_accu(char *str, t_printf *pf, int *sign, char *str2)
// {
// 	char	*whitespace;
// 	size_t	lmalloc;
// 	size_t	lenstr;
// 	char	*result;

// 	// dprintf(1, "str\t: %s\nstr2\t: %s\n", str, str2);
// 	lenstr = ft_strlen(str) + ft_strlen(str2);
// 	if (*sign && !ft_is_in_flags('-', pf))
// 		str = ft_strfjoin("-", str, 0);
// 	lmalloc = (pf->width > lenstr ? pf->width - lenstr/* - missing*/ : 0);
// 	if (!(whitespace = ft_calloc(sizeof(char), lmalloc + 1)))
// 		return (NULL);
// 	ft_memset(whitespace, ' ', lmalloc);
// 	// dprintf(1, "sign\t: %c\n", *sign + '0');
// 	// dprintf(1, "str\t: %s\nlenstr\t: %zu\nwidth\t: %zu\naccu\t: %zu\n", str, lenstr, pf->width, pf->accu);
// 	// dprintf(1, "str\t: %s\nwhit\t: |%s|\n", str, whitespace);
// 	if (!ft_is_in_flags('-', pf))
// 	{
// 		result = ft_strfjoin(whitespace, str, 3);
// 		if(*sign)
// 		*sign = 0;
// 	}
// 	else 
// 		result = ft_strfjoin(str, whitespace, 3);
// 	return (result);
// }

// char	*ft_zero_flag(char *str, t_printf *pf, char sign)
// {
// 	size_t	lmalloc;
// 	size_t	lenstr;
// 	char	*tmp;
// 	lenstr = ft_strlen(str);
// 	//dprintf(1, "sign\t: %c\n", sign + '0');
// 	//dprintf(1, "str\t: %s\nlenstr\t: %zu\nwidth\t: %zu\naccu\t: %zu\n", str, lenstr, pf->width, pf->accu);
// 	if (ft_is_in_flags('0', pf) && ft_is_in_flags('.', pf))
// 		sign = 0;
// 	lmalloc = (pf->width >= lenstr ? pf->width - lenstr : 0);
// 	//dprintf(1, "lmalloc\t: %zu\n", lmalloc);
// 	if (!(tmp = ft_calloc(sizeof(char), lmalloc + 1)))
// 		return (NULL);
// 	if (ft_char_in_string('0', pf->flags) && !ft_is_in_flags('-', pf))
// 		ft_memset(tmp, '0', lmalloc);
// 	else
// 		ft_memset(tmp, ' ', lmalloc);
// 	//dprintf(1, "tmp\t: |%s|\n", tmp);
// 	return (tmp);
// }

char	*ft_del_neg(char *str)
{
	char		*tmp;
	
	if (!(tmp = ft_calloc(sizeof(char), (ft_strlen(str)))))
		return (NULL);
	ft_memcpy(tmp, str + 1, ft_strlen(str));
	ft_memcpy(str, tmp, ft_strlen(tmp) + 1);
	ft_strdel(&tmp);
	return (str);
}

char	*ft_apply_accu(char *str, t_printf *pf)
{
	//dprintf(1, "ft_apply_accu\nstr\t: |%s|\n", str);
	char	*tmp;
	
	if (ft_char_in_string(pf->option, "duixX"))
	{
		if (pf->accu > ft_strlen(str))
		{
			if (!(tmp = ft_calloc(sizeof(char), pf->accu - ft_strlen(str) + 1)))
				return (NULL);
			ft_memset(tmp, '0', pf->accu - ft_strlen(str));
			str = ft_strfjoin(tmp, str, 1);
		}
	}
	//dprintf(1, "str\t: |%s|\nlen\t: |%zu|\n", str, ft_strlen(str));
	return (str);
}

char	*ft_apply_width(char *str, t_printf *pf)
{
	// dprintf(1, "ft_apply_width\nstr\t: |%s|\n", str);
	char	*padding;
	size_t	lpadding;


	lpadding = pf->width - ft_strlen(str) - pf->sign;
	// dprintf(1, "lpadd\t: |%zu|\n", lpadding);
	if (!(padding = ft_calloc(sizeof(char), lpadding + 1)))
		return (NULL);
	if (ft_is_in_flags('0', pf) && !ft_is_in_flags('-', pf))
		ft_memset(padding, '0', lpadding);
	else
		ft_memset(padding, ' ', lpadding);
	if (!ft_is_in_flags('0', pf) && pf->sign && !ft_is_in_flags('-', pf) && pf->got_accu)
	{
		padding[0] = '-';
		pf->sign = 0;
	}
	else if (!ft_is_in_flags('0', pf) && pf->sign && !ft_is_in_flags('-', pf) && !pf->got_accu)
	{
		str = ft_strfjoin("-", str, 2);
		pf->sign = 0;
	}
	//dprintf(1, "str\t: |%s|\npadd\t: |%s|\n", str, padding);
	if(ft_is_in_flags('-', pf))
		str = ft_strfjoin(str, padding, 3);
	else
		str = ft_strfjoin(padding, str, 3);
	return (str);
}

char	*ft_apply_flags(char *str, t_printf *pf)
{
	// dprintf(1, "str\t: |%s|\nflags\t: %s\nwidth\t: %zu\naccu\t: %zu\n",str, pf->flags, pf->width, pf->accu);
	pf->sign = (str[0] == '-');
	if (pf->sign)
		str = ft_del_neg(str);
	str = ft_zero_str(str, pf);
	// dprintf(1, "str\t: %s\n", str);
	if (pf->got_accu)
		str = ft_apply_accu(str, pf);
	if (pf->width >= ft_strlen(str) + pf->sign)
		str = ft_apply_width(str, pf);
	if	(pf->sign)
		str = ft_strfjoin("-", str, 2);
	return (str);
}