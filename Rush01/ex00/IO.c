/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_correct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:38:07 by baltes-g          #+#    #+#             */
/*   Updated: 2022/07/17 19:44:01 by pbrossa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		i++;
	}
	return (i);
}

int	input_correct(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < 32)
	{
		if (argv[1][i] < '0' || argv[1][i] > '4')
		{
			return (0);
		}
		++i;
		if (argv[1][i] > 32)
		{
			return (0);
		}
		++i;
	}
	j = ft_strlen(argv);
	if (j != 31)
	{
		return (0);
	}
	return (1);
}

int	*get_input(char **argv)
{
	static int	lim[16];
	int			i;

	i = 0;
	while (i < 16)
	{
		lim[i] = argv[1][2 * i] - 48;
		++i;
	}
	return (lim);
}
