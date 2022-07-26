/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_correct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:38:07 by baltes-g          #+#    #+#             */
/*   Updated: 2022/07/17 16:14:22 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	input_correct(char **argv)
{
	int	i;

	i = 0;
	while (i < 72)
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
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
	return (1);
}

int	*get_input(char **argv)
{
	static int	lim[36];
	int			i;

	i = 0;
	while (i < 36)
	{
		lim[i] = argv[1][2 * i] - 48;
		++i;
	}
	return (lim);
}
