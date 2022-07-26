/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:28:22 by baltes-g          #+#    #+#             */
/*   Updated: 2022/07/17 17:39:45 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int		is_valid(int i, int j, int limiters[20], int board[5][5]);
void	printboard(int board[5][5]);

void	backtracking(int i, int j, int limiters[20], int board[5][5])
{
	if (i == 4 && j == 4 && is_valid(i, j, limiters, board))
		printboard(board);
	else if (i == 0 && j == 0 && board[0][0] == 6)
		write(1, "error: bad board\n", 17);
	else
	{
		if (is_valid(i, j, limiters, board))
		{
			if (j == 4)
			{
				++board[i + 1][0];
				backtracking(i + 1, 0, limiters, board);
			}
			else
			{
				++board[i][j + 1];
				backtracking(i, j + 1, limiters, board);
			}
		}
		else
		{
			board[i][j]++;
			if (board[i][j] < 6)
			{
				backtracking(i, j, limiters, board);
			}
			else
			{
				if (i == 0 && j == 0)
				{
					backtracking(i, j, limiters, board);
					return ;
				}
				board[i][j] = 0;
				if (j == 0)
				{
					board[i - 1][4]++;
					backtracking(i - 1, 4, limiters, board);
				}
				else
				{
					board[i][j - 1]++;
					backtracking(i, j - 1, limiters, board);
				}
			}
		}
	}
}	
