/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:27:51 by baltes-g          #+#    #+#             */
/*   Updated: 2022/07/17 15:01:54 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	upcorrecte(int j, int i, int limiters[16], int board[4][4]);
int	downcorrecte(int j, int i, int limiters[16], int board[4][4]);
int	leftcorrecte(int i, int j, int limiters[16], int board[4][4]);
int	rightcorrecte(int i, int j, int limiters[16], int board[4][4]);

int	filacorrecte(int i, int j, int board[4][4])
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (board[i][k] == board[i][j] && k != j)
		{
			return (0);
		}
		++k;
	}
	return (1);
}

int	colcorrecte(int i, int j, int board[4][4])
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (board[k][j] == board[i][j] && k != i)
		{
			return (0);
		}
		++k;
	}
	return (1);
}

int	is_valid(int i, int j, int limiters[16], int board[4][4])
{
	if (board[i][j] <= 4)
	{
		if (filacorrecte(i, j, board) && colcorrecte(i, j, board))
		{
			if (upcorrecte(j, i, limiters, board))
			{
				if (downcorrecte(j, i, limiters, board))
				{
					if (leftcorrecte(i, j, limiters, board))
					{
						if (rightcorrecte(i, j, limiters, board))
						{
							return (1);
						}
					}
				}
			}
		}
	}
	return (0);
}
