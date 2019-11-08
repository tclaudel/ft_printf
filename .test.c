/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:15:11 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 13:44:37 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"


#include <stdio.h>

int		main(void)
{
	char *str = "ap1 : %.50s ap2 : %.015p ap3 = %s";
	char *ap1 = "coucou";
	int ap2 = 50;
	char *ap3 = "ap3";
	char *str2 = ft_strdup(str);
	// dprintf(1, ">-------------------------------------------------------------------------------<\n\nSETUP :\nstr :\t%s\n\t012345678901234567890123456789\nap1 :\t%s\nap2 :\t%d\nap3 :\t%s\n", str, ap1, ap2, ap3);
	// dprintf(1, "\tRESULT : |");
	// ft_printf("ft_printf = Test0d /%.15p/ /%010d/ /%-05d/ /%08.5d/", ap1, 487, 487, 487);
	// dprintf(1, "|\n\tPRINTF : |");
	// dprintf(1, "expected =  Test0d /%.15p/ /%010d/ /%-05d/ /%08.5d/", ap1, 487, 487, 487);
	// dprintf(1, "|\n");
	printf("%p %c %c %-50s", "test", '\0', '\0', "bonnjjode");
	ft_printf("%p %c %c %-50s", "test", '\0', '\0', "bonnjjode");
	free(str2);
}