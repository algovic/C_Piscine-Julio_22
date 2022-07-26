/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:17:03 by baltes-g          #+#    #+#             */
/*   Updated: 2022/07/17 16:15:20 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	printboard(int board[9][9])
{
	int		k;
	int		j;
	char	aux;

	k = 0;
	while (k < 9)
	{
		j = 0;
		while (j < 9)
		{
			aux = board[k][j] + '0';
			write(1, &aux, 1);
			if (j != 8)
			{
				write(1, " ", 1);
			}
			j++;
		}
		k++;
		write(1, "\n", 1);
	}
}
