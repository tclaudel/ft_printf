/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_apply_flags.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 14:30:58 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 13:01:41 by tclaudel    ###    #+. /#+    ###.fr     */
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
// 		zero = ft_width_accu(zero, pf, sign, &str);
// 	//dprintf(1, "zero\t: |%s|\n", zero);
// 	return (zero);
// }

// char	*ft_width_accu(char *str, t_printf *pf, int *sign, char **str2)
// {
// 	char	*whitespace;
// 	size_t	lmalloc;
// 	size_t	lenstr;
// 	char	*result;

// 	// dprintf(1, "str\t: |%s|\nstr2\t: |%s|\n", str, *str2);
// 	lenstr = ft_strlen(str) + ft_strlen(*str2);
// 	if (*sign && !ft_is_in_flags('-', pf))
// 		str = ft_strfjoin("-", str, 0);
// 	lmalloc = (pf->width > lenstr ? pf->width - lenstr/* - missing*/ : 0);
// 	if (!(whitespace = ft_calloc(sizeof(char), lmalloc + 1)))
// 		return (NULL);
// 	ft_memset(whitespace, ' ', lmalloc);
// 	// dprintf(1, "sign\t: %c\n", *sign + '0');
// 	// dprintf(1, "str\t: %s\nlenstr\t: %zu\nwidth\t: %zu\naccu\t: %zu\n", str, lenstr, pf->width, pf->accu);
// 	// dprintf(1, "str\t: %s\nwhit\t: |%s|\n", str, whitespace);
// 	if(pf->width > pf->accu && pf->accu != 0 && ft_is_in_flags('-', pf))
// 	{
// 		result = ft_strfjoin(str, *str2, 0);
// 		// dprintf(1,"white\t: |%s|\n", whitespace);
// 		free(*str2);
// 		*str2 = ft_strdup(whitespace);
// 	}
// 	else if (!ft_is_in_flags('-', pf))
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

char	*ft_apply_int(char *str, t_printf *pf, char sign)
{
	char	*tmp[2];

	dprintf(1, "str\t: |%s|\nsign\t: |%c|\n", str, sign + '0');
	if (pf->accu > ft_strlen(str))
	{
		if (!(tmp[0] = ft_calloc(sizeof(char), pf->accu - ft_strlen(str) + 1)))
			return (NULL);
		ft_memset(tmp[0], '0', pf->accu - ft_strlen(str));
	}
	else
		tmp[0] = ft_calloc(sizeof(char), 1);
	dprintf(1, "diff\t: |%zu|\n", pf->width - ft_strlen(tmp[0])- 1);
	if (pf->width >= pf->accu + ft_strlen(str))
	{
		puts("prout");
		if (!(tmp[1] = ft_calloc(sizeof(char), pf->width - ft_strlen(tmp[0])- 1)))
			return (NULL);
		ft_memset(tmp[1], ' ', pf->width - (pf->accu + ft_strlen(str)) + 1);
	}
	else
		tmp[1] = ft_calloc(sizeof(char), 1);
	str = ft_zero_str(str, pf);
	if (sign && ft_is_in_flags('0',pf))
		tmp[1] = ft_strfjoin("-", tmp[1], 2);
	else if (sign && !ft_is_in_flags('0',pf))
		tmp[0] = ft_strfjoin("-", tmp[0], 2);
	dprintf(1,"tmp[0]\t: |%s|\ntmp[1]\t: |%s|\nstr\t: |%s|\n", tmp[0], tmp[1], str);
	tmp[0] = ft_strfjoin(tmp[0], str, 0);
	dprintf(1,"tmp[0]\t: |%s|\ntmp[1]\t: |%s|\nstr\t: |%s|\n", tmp[0], tmp[1], str);
	//dprintf(1, "joined\t: |%s|\n", tmp[0]);
	if(!ft_is_in_flags('-', pf) && (pf->width >= pf->accu + ft_strlen(str)))
		tmp[0] = ft_strfjoin(tmp[1], tmp[0], 0);
	else
		tmp[0] = ft_strfjoin(tmp[0], tmp[1], 0);
	return (tmp[0]);
}

char	*ft_apply_flags(char *str, t_printf *pf)
{
	char	*tmp;
	int		sign;
	sign = (str[0] == '-');
	dprintf(1, "STR\t: |%s|\n", str);
	if (sign)
		str = ft_del_neg(str);
	if (pf->width + 1 > ft_strlen(str))
		pf->width -= sign;
	if (ft_char_in_string(pf->option, "diuxX"))
		tmp = ft_apply_int(str, pf, sign);
	else
		tmp = str;
	// dprintf(1, "str\t: |%s|\ntmp\t: |%s|\n", str, tmp);
	// if (!ft_char_in_string('-', pf->flags) || (ft_char_in_string(pf->option, "diuxX") && sign))
	// 	str = ft_strfjoin(tmp, str, 3);
	// else
	// 	str = ft_strfjoin(str, tmp, 3);
	// dprintf(1, "sign\t: %c\n", sign + '0');
	ft_bzero(pf->flags, 5);
	//dprintf(1, "FINAL STR : %s\n", str);
	return (tmp);
}