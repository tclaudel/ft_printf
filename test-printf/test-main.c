/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test-printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 16:54:40 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 15:17:35 by aalleman    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <wchar.h>
#include <locale.h>

int		ft_printf(const char *s, ...);

int		main(int ac, char **av)
{
	int		nb;
	int		count;

	nb = atoi(av[1]);
	count = 0;


	// [D - Tests with flag 0].
	if (nb == count++)
		return(ac == 2 ? printf("%01i", 0) : ft_printf("%01i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02i", 0) : ft_printf("%02i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010i", 0) : ft_printf("%010i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01i", -1) : ft_printf("%01i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02i", -1) : ft_printf("%02i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03i", -1) : ft_printf("%03i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09i", INT_MAX) : ft_printf("%09i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010i", INT_MAX) : ft_printf("%010i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011i", INT_MAX) : ft_printf("%011i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01d", 0) : ft_printf("%01d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02d", 0) : ft_printf("%02d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010d", 0) : ft_printf("%010d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01d", -1) : ft_printf("%01d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02d", -1) : ft_printf("%02d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03d", -1) : ft_printf("%03d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09d", INT_MAX) : ft_printf("%09d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010d", INT_MAX) : ft_printf("%010d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011d", INT_MAX) : ft_printf("%011d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01u", 0) : ft_printf("%01u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02u", 0) : ft_printf("%02u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010u", 0) : ft_printf("%010u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01u", -1) : ft_printf("%01u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02u", -1) : ft_printf("%02u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03u", -1) : ft_printf("%03u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09u", UINT_MAX) : ft_printf("%09u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010u", UINT_MAX) : ft_printf("%010u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011u", UINT_MAX) : ft_printf("%011u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01x", 0) : ft_printf("%01x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02x", 0) : ft_printf("%02x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010x", 0) : ft_printf("%010x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01x", -1) : ft_printf("%01x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02x", -1) : ft_printf("%02x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03x", -1) : ft_printf("%03x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09x", UINT_MAX) : ft_printf("%09x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010x", UINT_MAX) : ft_printf("%010x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011x", UINT_MAX) : ft_printf("%011x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01X", 0) : ft_printf("%01X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02X", 0) : ft_printf("%02X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010X", 0) : ft_printf("%010X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01X", -1) : ft_printf("%01X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02X", -1) : ft_printf("%02X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03X", -1) : ft_printf("%03X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09X", UINT_MAX) : ft_printf("%09X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010X", UINT_MAX) : ft_printf("%010X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011X", UINT_MAX) : ft_printf("%011X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%0-10d", 42) : ft_printf("%0-10d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%-010d", 42) : ft_printf("%-010d", 42));

	// [E - Tests with .].
return (0);
}
