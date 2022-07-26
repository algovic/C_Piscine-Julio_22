/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:57:45 by baltes-g          #+#    #+#             */
/*   Updated: 2022/07/17 17:39:18 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	upcorrecte(int j, int i, int limiters[20], int board[5][5])
{
	int	max;
	int	k;
	int	sum;

	i = 0;
	sum = 0;
	max = 0;
	k = 0;
	while (k < 5)
	{
		if (board[k][j] > max && board[k][j] != 0)
		{
			max = board[k][j];
			++sum;
		}
		++k;
	}
	if (sum <= limiters[j])
		return (1);
	return (0);
}

int	downcorrecte(int j, int i, int limiters[20], int board[5][5])
{
	int	max;
	int	k;
	int	sum;

	sum = 0;
	max = 0;
	k = 4;
	while (k >= 0)
	{
		if (board[k][j] > max && board[k][j] != 0)
		{
			max = board[k][j];
			++sum;
		}
		--k;
	}
	if (i == 4)
	{
		if (sum != limiters[5 + j])
			return (0);
	}
	return (1);
}

int	leftcorrecte(int i, int j, int limiters[20], int board[5][5])
{
	int	max;
	int	k;
	int	sum;

	sum = 0;
	max = 0;
	k = 0;
	while (k < 5)
	{
		if (board[i][k] > max && board[i][k] != 0)
		{
			max = board[i][k];
			++sum;
		}
		++k;
	}
	if (j == 4)
	{
		if (sum == limiters[10 + i])
			return (1);
	}
	if (sum <= limiters[10 + i])
		return (1);
	return (0);
}

int	rightcorrecte(int i, int j, int limiters[20], int board[5][5])
{
	int	max;
	int	k;
	int	sum;

	sum = 0;
	max = 0;
	k = 4;
	while (k >= 0)
	{
		if (board[i][k] > max && board[i][k] != 0)
		{
			max = board[i][k];
			++sum;
		}
		--k;
	}
	if (j == 4)
	{
		if (sum != limiters[15 + i])
			return (0);
	}
	return (1);
}
