/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:15:11 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 09:14:30 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>
#include <limits.h>

void	print_error (size_t *i)
{
	dprintf(1, "\033[1;31m");
	dprintf(1, "return : KO\n\n");
	dprintf(1, "\033[0m");
	*i += 1;
}

void	print_ok (size_t *i)
{
	dprintf(1, "\033[0;32m");
	dprintf(1, "return : OK\n\n");
	dprintf(1, "\033[0m");
	*i += 1;
}

void	print_undef ()
{
	dprintf(1, "\033[3;32m");
	dprintf(1, "undefined\n\n");
	dprintf(1, "\033[0m");
}

void	print_testing (char *str)
{
	dprintf(1, "\033[3;90m");
	dprintf(1, "testing \t%s\n", str);
	dprintf(1, "\033[0m");
}

void	print_result(size_t tested, size_t ok, size_t ko)
{
	size_t pourcentok;

	pourcentok = ok * 100 / tested;
	dprintf(1, ">------------------ RESULT ------------------<\n\n");

	dprintf(1, "\033[1;90m");
	dprintf(1, "\tTESTED : %zu\n", tested);
	dprintf(1, "\033[0m");
	if (pourcentok == 100)
	{
		dprintf(1, "\033[1;32m");
		dprintf(1, "\t%zu TEST FULL PASSED\n", ok);
		dprintf(1, "\033[0m");
	}
	else 
	{
		dprintf(1, "\033[1;31m");
		dprintf(1, "\t%zu%% failed\n", 100 -pourcentok);
		dprintf(1, "\t%zu errors found\n", ko);
		dprintf(1, "\033[0m");
	}
	
	dprintf(1, "\n>--------------------------------------------<\n");

}


int		main(void)
{
	size_t	tested = 0;
	size_t	testok = 0;
	size_t	testko = 0;
	
	fflush(stdout);

	dprintf(1, ">--------------- CLASSIC TEST ---------------<\n\n");
	
	tested++;
	print_testing("bonjour");
	if (printf("printf    :\tbonjour\n") == ft_printf("ft_printf :\tbonjour\n"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("");
	if (printf("") == ft_printf(""))
		print_ok(&testok);
	else
		print_error(&testko);

	dprintf(1, ">------------------ D TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%.d\\n|\", 0");
	if (printf("printf    :\t|%.d|\n", 0) == ft_printf("ft_printf :\t|%.d|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.45d\\n|\", 0");
	if (printf("printf    :\t|%.45d|\n", 0) == ft_printf("ft_printf :\t|%.45d|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%45d\\n|\", -87");
	if (printf("printf    :\t|%45d|\n", -87) == ft_printf("ft_printf :\t|%45d|\n", -87))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%*d\\n|\", -9, -87");
	if (printf("printf    :\t|%*d|\n", -9, -87) == ft_printf("ft_printf :\t|%*d|\n", -9, -87))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-*d\\n|\", -9, -87");
	if (printf("printf    :\t|%-*d|\n", -9, -87) == ft_printf("ft_printf :\t|%-*d|\n", -9, -87))
		print_ok(&testok);
	else
		print_error(&testko);

	print_testing("\"%.*d|\\n\", 45");
	if (ft_printf("ft_printf :\t|%.*d|\n", 45))
		print_undef();

	tested++;
	print_testing("\"|%.*d|\\n\", 0, 45");
	if (printf("printf    :\t|%.*d|\n", 0, 45) == ft_printf("ft_printf :\t|%.*d|\n", 0, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.*d|\\n\", 45, 0");
	if (printf("printf    :\t|%.*d|\n", 45, 0) == ft_printf("ft_printf :\t|%.*d|\n", 45, 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%d|\\n\", 45");
	if (printf("printf    :\t|%d|\n", 45) == ft_printf("ft_printf :\t|%d|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%--d|\\n\", 45");
	if (printf("printf    :\t|%--d|\n", 45) == ft_printf("ft_printf :\t|%--d|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.046d|\\n\", 45");
	if (printf("printf    :\t|%.046d|\n", 45) == ft_printf("ft_printf :\t|%.046d|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046d|\\n\", 45");
	if (printf("printf    :\t|%046d|\n", 45) == ft_printf("ft_printf :\t|%046d|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-*046d|\\n\", 15, 45");
	if (printf("printf    :\t|%-*d|\n", 15, 45) == ft_printf("ft_printf :\t|%-*d|\n", 15, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	ft_printf("ft_printf :\t|%**46d|\n", 15, 10, 45);
		print_undef();

	tested++;
	print_testing("\"|%*d|\\n\", -9, 45");
	if (printf("printf    :\t|%*d|\n", -9, 45) == ft_printf("ft_printf :\t|%*d|\n", -9, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-*d|\\n\", -9, 45");
	if (printf("printf    :\t|%-*d|\n", -9, 45) == ft_printf("ft_printf :\t|%-*d|\n", -9, 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%046d|\\n\", INT_MIN");
	if (printf("printf    :\t|%046d|\n", INT_MIN) == ft_printf("ft_printf :\t|%046d|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046d|\\n\", INT_MAX");
	if (printf("printf    :\t|%046d|\n", INT_MAX) == ft_printf("ft_printf :\t|%046d|\n", INT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%d|\\n\", INT_MIN");
	if (printf("printf    :\t|%d|\n", INT_MIN) == ft_printf("ft_printf :\t|%d|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-55d|\\n\", INT_MIN");
	if (printf("printf    :\t|%-55d|\n", INT_MIN) == ft_printf("ft_printf :\t|%-55d|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%d|\\n\", INT_MAX");
	if (printf("printf    :\t|%d|\n", INT_MAX) == ft_printf("ft_printf :\t|%d|\n", INT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54d|\\n\", INT_MIN");
	if (printf("printf    :\t|%-54d|\n", INT_MIN) == ft_printf("ft_printf :\t|%-54d|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%d|\\n\", INT_MAX");
	if (printf("printf    :\t|%-54d|\n", INT_MAX) == ft_printf("ft_printf :\t|%-54d|\n", INT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

dprintf(1, ">------------------ I TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%.i\\n|\", 0");
	if (printf("printf    :\t|%.i|\n", 0) == ft_printf("ft_printf :\t|%.i|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%45i\\n|\", -16");
	if (printf("printf    :\t|%45i|\n", -16) == ft_printf("ft_printf :\t|%45i|\n", -16))
		print_ok(&testok);
	else
		print_error(&testko);

	print_testing("\"%.*i|\\n\", 45");
	if (ft_printf("ft_printf :\t|%.*i|\n", 45))
		print_undef();

	tested++;
	print_testing("\"|%.*i|\\n\", 0, 45");
	if (printf("printf    :\t|%.*i|\n", 0, 45) == ft_printf("ft_printf :\t|%.*i|\n", 0, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.*i|\\n\", 45, 0");
	if (printf("printf    :\t|%.*i|\n", 45, 0) == ft_printf("ft_printf :\t|%.*i|\n", 45, 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%i|\\n\", 45");
	if (printf("printf    :\t|%i|\n", 45) == ft_printf("ft_printf :\t|%i|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.46i|\\n\", 45");
	if (printf("printf    :\t|%.46i|\n", 45) == ft_printf("ft_printf :\t|%.46i|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%046i|\\n\", -2147483648");
	if (printf("printf    :\t|%046i|\n", -2147483647) == ft_printf("ft_printf :\t|%046i|\n", -2147483647))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046i|\\n\", INT_MIN");
	if (printf("printf    :\t|%046i|\n", INT_MIN) == ft_printf("ft_printf :\t|%046i|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046i|\\n\", INT_MAX");
	if (printf("printf    :\t|%046i|\n", INT_MAX) == ft_printf("ft_printf :\t|%046i|\n", INT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%i|\\n\", INT_MIN");
	if (printf("printf    :\t|%i|\n", INT_MIN) == ft_printf("ft_printf :\t|%i|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%i|\\n\", INT_MAX");
	if (printf("printf    :\t|%i|\n", INT_MAX) == ft_printf("ft_printf :\t|%i|\n", INT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%i|\\n\", INT_MIN - 1");
	if (printf("printf    :\t|%i|\n", INT_MIN - 1) == ft_printf("ft_printf :\t|%i|\n", INT_MIN - 1))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%i|\\n\", INT_MAX + 1");
	if (printf("printf    :\t|%i|\n", INT_MAX + 1) == ft_printf("ft_printf :\t|%i|\n", INT_MAX + 1))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54i|\\n\", INT_MIN");
	if (printf("printf    :\t|%-54i|\n", INT_MIN) == ft_printf("ft_printf :\t|%-54i|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%i|\\n\", INT_MAX");
	if (printf("printf    :\t|%-54i|\n", INT_MAX) == ft_printf("ft_printf :\t|%-54i|\n", INT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

dprintf(1, ">------------------ U TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%.u\\n|\", 0");
	if (printf("printf    :\t|%.u|\n", 0) == ft_printf("ft_printf :\t|%.u|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.45u\\n|\", 0");
	if (printf("printf    :\t|%.45u|\n", 0) == ft_printf("ft_printf :\t|%.45u|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	print_testing("\"%.*u|\\n\", 45");
	if (ft_printf("ft_printf :\t|%.*u|\n", 45))
		print_undef();

	tested++;
	print_testing("\"|%.*u|\\n\", 0, 45");
	if (printf("printf    :\t|%.*u|\n", 0, 45) == ft_printf("ft_printf :\t|%.*u|\n", 0, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.*u|\\n\", 45, 0");
	if (printf("printf    :\t|%.*u|\n", 45, 0) == ft_printf("ft_printf :\t|%.*u|\n", 45, 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%u|\\n\", 45");
	if (printf("printf    :\t|%u|\n", 45) == ft_printf("ft_printf :\t|%u|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.46u|\\n\", 45");
	if (printf("printf    :\t|%.46u|\n", 45) == ft_printf("ft_printf :\t|%.46u|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%046u|\\n\", -2147483648");
	if (printf("printf    :\t|%046u|\n", -2147483647) == ft_printf("ft_printf :\t|%046u|\n", -2147483647))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046u|\\n\", 0");
	if (printf("printf    :\t|%046u|\n", 0) == ft_printf("ft_printf :\t|%046u|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046u|\\n\", UINT_MAX");
	if (printf("printf    :\t|%046u|\n", UINT_MAX) == ft_printf("ft_printf :\t|%046u|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%u|\\n\", 0");
	if (printf("printf    :\t|%u|\n", 0) == ft_printf("ft_printf :\t|%u|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%u|\\n\", UINT_MAX");
	if (printf("printf    :\t|%u|\n", UINT_MAX) == ft_printf("ft_printf :\t|%u|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54u|\\n\", 0");
	if (printf("printf    :\t|%-54u|\n", 0) == ft_printf("ft_printf :\t|%-54u|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%u|\\n\", UINT_MAX");
	if (printf("printf    :\t|%-54u|\n", UINT_MAX) == ft_printf("ft_printf :\t|%-54u|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	dprintf(1, ">------------------ x TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%.x\\n|\", 0");
	if (printf("printf    :\t|%.x|\n", 0) == ft_printf("ft_printf :\t|%.x|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.45x\\n|\", 0");
	if (printf("printf    :\t|%.45x|\n", 0) == ft_printf("ft_printf :\t|%.45x|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);


	print_testing("\"%.*x|\\n\", 45");
	if (ft_printf("ft_printf :\t|%.*x|\n", 45))
		print_undef();

	tested++;
	print_testing("\"|%.*x|\\n\", 0, 45");
	if (printf("printf    :\t|%.*x|\n", 0, 45) == ft_printf("ft_printf :\t|%.*x|\n", 0, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.*x|\\n\", 45, 0");
	if (printf("printf    :\t|%.*x|\n", 45, 0) == ft_printf("ft_printf :\t|%.*x|\n", 45, 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%x|\\n\", 45");
	if (printf("printf    :\t|%x|\n", 45) == ft_printf("ft_printf :\t|%x|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.46x|\\n\", 45");
	if (printf("printf    :\t|%.46x|\n", 45) == ft_printf("ft_printf :\t|%.46x|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046x|\\n\", 0");
	if (printf("printf    :\t|%046x|\n", 0) == ft_printf("ft_printf :\t|%046x|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046x|\\n\", UINT_MAX");
	if (printf("printf    :\t|%046x|\n", UINT_MAX) == ft_printf("ft_printf :\t|%046x|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%x|\\n\", 0");
	if (printf("printf    :\t|%x|\n", 0) == ft_printf("ft_printf :\t|%x|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%x|\\n\", UINT_MAX");
	if (printf("printf    :\t|%x|\n", UINT_MAX) == ft_printf("ft_printf :\t|%x|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54x|\\n\", 0");
	if (printf("printf    :\t|%-54x|\n", 0) == ft_printf("ft_printf :\t|%-54x|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54x|\\n\", UINT_MAX");
	if (printf("printf    :\t|%-54x|\n", UINT_MAX) == ft_printf("ft_printf :\t|%-54x|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);
	
	dprintf(1, ">------------------ X TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%.X\\n|\", 0");
	if (printf("printf    :\t|%.X|\n", 0) == ft_printf("ft_printf :\t|%.X|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.45X\\n|\", 0");
	if (printf("printf    :\t|%.45X|\n", 0) == ft_printf("ft_printf :\t|%.45X|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);


	print_testing("\"%.*X|\\n\", 45");
	if (ft_printf("ft_printf :\t|%.*X|\n", 45))
		print_undef();

	tested++;
	print_testing("\"|%.*X|\\n\", 0, 45");
	if (printf("printf    :\t|%.*X|\n", 0, 45) == ft_printf("ft_printf :\t|%.*X|\n", 0, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.*X|\\n\", 45, 0");
	if (printf("printf    :\t|%.*X|\n", 45, 0) == ft_printf("ft_printf :\t|%.*X|\n", 45, 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%X|\\n\", 45");
	if (printf("printf    :\t|%X|\n", 45) == ft_printf("ft_printf :\t|%X|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%X|\\n\", 20");
	if (printf("printf    :\t|%X|\n", 20) == ft_printf("ft_printf :\t|%X|\n", 20))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.46X|\\n\", 45");
	if (printf("printf    :\t|%.46X|\n", 45) == ft_printf("ft_printf :\t|%.46X|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046X|\\n\", 0");
	if (printf("printf    :\t|%046X|\n", 0) == ft_printf("ft_printf :\t|%046X|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046X|\\n\", UINT_MAX");
	if (printf("printf    :\t|%046X|\n", UINT_MAX) == ft_printf("ft_printf :\t|%046X|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%X|\\n\", 0");
	if (printf("printf    :\t|%X|\n", 0) == ft_printf("ft_printf :\t|%X|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%X|\\n\", UINT_MAX");
	if (printf("printf    :\t|%X|\n", UINT_MAX) == ft_printf("ft_printf :\t|%X|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54X|\\n\", 0");
	if (printf("printf    :\t|%-54X|\n", 0) == ft_printf("ft_printf :\t|%-54X|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%X|\\n\", UINT_MAX");
	if (printf("printf    :\t|%-54X|\n", UINT_MAX) == ft_printf("ft_printf :\t|%-54X|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	dprintf(1, ">------------------ S TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%s|\\n\", bonjour");
	if (printf("printf    :\t|%s|\n", "bonjour") == ft_printf("ft_printf :\t|%s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%5s|\\n\", bonjour");
	if (printf("printf    :\t|%5s|\n", "bonjour") == ft_printf("ft_printf :\t|%5s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.5s|\\n\", bonjour");
	if (printf("printf    :\t|%.5s|\n", "bonjour") == ft_printf("ft_printf :\t|%.5s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%*5s|\\n\",  5,bonjour");
	if (printf("printf    :\t|%*s|\n", 5, "bonjour") == ft_printf("ft_printf :\t|%*s|\n", 5,"bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%*s|\\n\",  -50, bonjour");
	if (printf("printf    :\t|%*s|\n", -50, "bonjour") == ft_printf("ft_printf :\t|%*s|\n", -50,"bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	// tested++;
	// print_testing("\"|%.-50s|\\n\",  bonjour");
	// if (printf("printf    :\t|%.-50s|\n", "bonjour") == ft_printf("ft_printf :\t|%.-50s|\n", "bonjour"))
	// 	print_ok(&testok);
	// else
	// 	print_error(&testko);

	tested++;
	print_testing("\"|%16s|\\n\", bonjour");
	if (printf("printf    :\t|%16s|\n", "bonjour") == ft_printf("ft_printf :\t|%16s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.16s|\\n\", bonjour");
	if (printf("printf    :\t|%.16s|\n", "bonjour") == ft_printf("ft_printf :\t|%.16s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%*16s|\\n\",  16,bonjour");
	if (printf("printf    :\t|%*s|\n", 16, "bonjour") == ft_printf("ft_printf :\t|%*s|\n", 16,"bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);


	print_testing("\"|%.*5s|\\n\", 16, bonjour");
	ft_printf("ft_printf :\t|%.*5s|\n", 16, "bonjour");
	print_undef();
	
	tested++;
	print_testing("\"|%-50s|\\n\", \"bonjour");
	if (printf("printf    :\t|%-50s|\n", "bonjour") == ft_printf("ft_printf :\t|%-50s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	print_testing("\"|%-050s|\\n\", \"bonjour");
	ft_printf("ft_printf :\t|%-050s|\n", "bonjour");
	print_undef();

	tested++;
	print_testing("\"|%*s|\\n\", 15, NULL");
	if (printf("printf    :\t|%*s|\n", 15, NULL) == ft_printf("ft_printf :\t|%*s|\n", 15,  NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-46s|\\n\", NULL");
	if (printf("printf    :\t|%-46s|\n", NULL) == ft_printf("ft_printf :\t|%-46s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.46s|\\n\", NULL");
	if (printf("printf    :\t|%.46s|\n", NULL) == ft_printf("ft_printf :\t|%.46s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.46s|\\n\", \"\"");
	if (printf("printf    :\t|%.46s|\n", "") == ft_printf("ft_printf :\t|%.46s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%46s|\\n\", \"\"");
	if (printf("printf    :\t|%46s|\n", "") == ft_printf("ft_printf :\t|%46s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%46.0s|\\n\", \"\"");
	if (printf("printf    :\t|%46.0s|\n", "") == ft_printf("ft_printf :\t|%46.0s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	print_testing("\"|%0.46s|\\n\", \"\"");
	ft_printf("ft_printf :\t|%046s|\n", "");
		print_undef();
	
	tested++;
	print_testing("\"|%s|\\n\", bonj\\200our");
	if (printf("printf    :\t|%s|\n", "bonj\200our") == ft_printf("ft_printf :\t|%s|\n", "bonj\200our"))
		print_ok(&testok);
	else
		print_error(&testko);

	dprintf(1, ">------------------ C TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%46c|\\n\", 'c'");
	if (printf("printf    :\t|%46c|\n", 'c') == ft_printf("ft_printf :\t|%46c|\n", 'c'))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-46c|\\n\", 0");
	if (printf("printf    :\t|%-46c|\n", 0) == ft_printf("ft_printf :\t|%-46c|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%c|\\n\", 'c'");
	if (printf("printf    :\t|%c|\n", 'c') == ft_printf("ft_printf :\t|%c|\n", 'c'))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%c%c|\\n\", 'c', 0");
	if (printf("printf    :\t|%c%c|\n", 'c', 0) == ft_printf("ft_printf :\t|%c%c|\n", 'c', 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%c*8%c|\\n\", 'c', 0");
	if (printf("printf    :\t|%c*8%c|\n", 'c', 0) == ft_printf("ft_printf :\t|%c*8%c|\n", 'c', 0))
		print_ok(&testok);
	else
		print_error(&testko);

	ft_printf("ft_printf :\t|%.0c|\n", 'c');
		print_undef();

	dprintf(1, ">------------------ P TEST ------------------<\n\n");

	char *str = ft_strdup("bonjour");

	print_testing("\"|%p|\\n\", 0");
	ft_printf("ft_printf :\t|%p|\n", 0);
	print_undef();

	tested++;
	print_testing("\"|%p|\\n\", NULL");
	if (printf("printf    :\t|%p|\n", NULL) == ft_printf("ft_printf :\t|%p|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%p|\\n\", &str + 100000");
	if (printf("printf    :\t|%p|\n", str + 100000) == ft_printf("ft_printf :\t|%p|\n", str + 100000))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%p|\\n\", &tested");
	if (printf("printf    :\t|%p|\n", &tested) == ft_printf("ft_printf :\t|%p|\n", &tested))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%p|\\n\", &str");
	if (printf("printf    :\t|%p|\n", str) == ft_printf("ft_printf :\t|%p|\n", str))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%54p|\\n\", NULL");
	if (printf("printf    :\t|%54p|\n", NULL) == ft_printf("ft_printf :\t|%54p|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	print_testing("\"|%054p|\\n\", NULL");
	ft_printf("ft_printf :\t|%0.54p|\n", NULL);
		print_undef();

	tested++;
	print_testing("\"|%p|\\n\", NULL");
	if (printf("printf    :\t|%p|\n", NULL) == ft_printf("ft_printf :\t|%p|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	ft_strdel(&str);

	dprintf(1, ">---------------- MORGAN TEST ---------------<\n\n");

	tested++;
	print_testing("\"|%.3s|\\n\", NULL");
	if (printf("printf    :\t|%.3s|\n", NULL) == ft_printf("ft_printf :\t|%.3s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%c|\\n\", 'c'");
	if (printf("printf    :\t|%c|\n", 0) == ft_printf("ft_printf :\t|%c|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	char *tmp;

	tmp = NULL;
	tested++;
	print_testing("\"|%p|\\n\", 0");
	if (printf("printf    :\t|%p|\n", tmp) == ft_printf("ft_printf :\t|%p|\n", tmp))
		print_ok(&testok);
	else
		print_error(&testko);

	tmp = ft_strdup("monais monaie mauney");
	tested++;
	print_testing("\"|%p|\\n\", 0");
	if (printf("printf    :\t|%p|\n", tmp) == ft_printf("ft_printf :\t|%p|\n", tmp))
		print_ok(&testok);
	else
		print_error(&testko);
	free(tmp);

	tested++;
	print_testing("\"|%.*s|\\n\",  -50, bonjour");
	if (printf("printf    :\t|%.*s|\n", -50, "bonjour") == ft_printf("ft_printf :\t|%.*s|\n", -50,"bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	// dprintf(1, ">---------------- ASCII TEST ---------------<\n\n");

	// print_testing("all ascii char");
	// unsigned int u;

	// u = 0;
	// while (u < 255)
	// {
	// 	tested++;
	// 	if (printf("printf    :\t|%c|\n", u) == ft_printf("ft_printf :\t|%c|\n", u))
	// 		testok++;
	// 	else
	// 	{
	// 		testko++;
	// 		print_error(&testko);
	// 	}
	// 	u++;
	// }

	// print_testing("all ascii char");

	// u = 0;
	// while (u < 255)
	// {
	// 	tested++;
	// 	if (printf("printf    :\t|%54c|\n", u) == ft_printf("ft_printf :\t|%54c|\n", u))
	// 		testok++;
	// 	else
	// 	{
	// 		testko++;
	// 		print_error(&testko);
	// 	}
	// 	u++;
	// }

	// print_testing("all ascii char");

	// u = 0;
	// while (u < 255)
	// {
	// 	tested++;
	// 	if (printf("printf    :\t|%-5c|\n", u) == ft_printf("ft_printf :\t|%-5c|\n", u))
	// 		testok++;
	// 	else
	// 	{
	// 		tested++;
	// 		print_error(&testko);
	// 	}
	// 	u++;
	// }

	print_result(tested, testok, testko);
}