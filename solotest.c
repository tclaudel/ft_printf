/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solotest.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:54:18 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 09:55:06 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>
#include <limits.h>

int		main(void)
{
	dprintf(1, "\ntesting\t: %s\n", "\"|%0*d|\", -10, 42");
	if ((printf("|%0*d|\n", -10, 42)) == (ft_printf("|%0*d|\n", -10, 42)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%0*d|\", 10, -42");
	if ((printf("|%0*d|\n", 10, -42)) == (ft_printf("|%0*d|\n", 10, -42)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%3i|\", -1");
	if ((printf("|%3i|\n", -1)) == (ft_printf("|%3i|\n", -1)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%3i|\", 0");
	if ((printf("|%3i|\n", 0)) == (ft_printf("|%3i|\n", 0)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%-2i|\", -1");
	if ((printf("|%-2i|\n", -1)) == (ft_printf("|%-2i|\n", -1)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%-1.2i|\", 0");
	if ((printf("|%-1.2i|\n", 0)) == (ft_printf("|%-1.2i|\n", 0)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%2.2i|\", 0");
	if ((printf("|%2.2i|\n", 0)) == (ft_printf("|%2.2i|\n", 0)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%.2i|\", 0");
	if ((printf("|%.2i|\n", 0)) == (ft_printf("|%.2i|\n", 0)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%i|\", 0");
	if ((printf("|%i|\n", 0)) == (ft_printf("|%i|\n", 0)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%.3i|\", -42");
	if ((printf("|%.3i|\n", -42)) == (ft_printf("|%.3i|\n", -42)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%-2.10%|\"");
	if ((printf("|%-2.10%|\n")) == (ft_printf("|%-2.10%|\n")))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	
	dprintf(1, "\ntesting\t: %s\n", "\"|%-3.2i|\", -1");
	if ((printf("|%-3.2i|\n", -1)) == (ft_printf("|%-3.2i|\n", -1)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	

	printf("TEST --> %-5.3Wonjour\n");
	ft_printf("TEST --> %-5.3Wonjour\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%.*d|\", -10");
	if ((printf("|%.*d|\n", -10, 42)) == (ft_printf("|%.*d|\n", -10, 42)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%-1.10x|\", -1");
	if ((printf("|%-1.10x|\n", -1)) == (ft_printf("|%-1.10x|\n", -1)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%-3.0i|\", -1");
	if ((printf("|%-3.0i|\n", -1)) == (ft_printf("|%-3.0i|\n", -1)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%-11.10x|\", 10");
	if ((printf("|%-11.10x|\n", 10)) == (ft_printf("|%-11.10x|\n", 10)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%01.0i|\", 0");
	if ((printf("|%01.0i|\n", 0)) == (ft_printf("|%01.0i|\n", 0)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	printf("TEST --> %-5.3Wonjour\n");
	ft_printf("TEST --> %-5.3Wonjour\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%0.*d|\", -45, 0");
	if ((printf("|%0.*d|\n", -45,0)) == (ft_printf("|%0.*d|\n", -45, 0)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	
}