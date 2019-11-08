/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:15:11 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 13:42:08 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>

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


	// print_testing("\"%.*d|\\n\", 45");
	// if (ft_printf("ft_printf :\t|%.*d|\n", 45))
	// 	print_undef();

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
	print_testing("\"|%.46d|\\n\", 45");
	if (printf("printf    :\t|%.46d|\n", 45) == ft_printf("ft_printf :\t|%.46d|\n", 45))
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

	// tested++;
	// print_testing("\"|%.46s|\\n\", NULL");
	// if (printf("printf    :\t|%.46s|\n", NULL) == ft_printf("ft_printf :\t|%.46s|\n", NULL))
	// 	print_ok(&testok);
	// else
	// 	print_error(&testko);

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

	tested++;
	print_testing("\"|%0.46s|\\n\", \"\"");
	if (printf("printf    :\t|%0.46s|\n", "") == ft_printf("ft_printf :\t|%0.46s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	ft_printf("ft_printf :\t|%046s|\n", "");
		print_undef();

	
	dprintf(1, ">------------------ C TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%46c|\\n\", 'c'");
	if (printf("printf    :\t|%46c|\n", 'c') == ft_printf("ft_printf :\t|%46c|\n", 'c'))
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

	print_result(tested, testok, testko);
}