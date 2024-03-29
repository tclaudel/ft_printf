/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_flag.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 17:10:06 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 18:22:40 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_is_flag(char c)
{
	char	*flags;
	int		i;

	i = 0;
	flags = "-0.*";
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}
