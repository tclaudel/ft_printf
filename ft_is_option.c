/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_option.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 17:06:57 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 10:40:52 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_is_option(char c)
{
	char	*options;
	int		i;

	i = 0;
	options = "cspdiuxX%";
	while (options[i])
	{
		if (options[i] == c)
			return (1);
		i++;
	}
	return (0);
}
