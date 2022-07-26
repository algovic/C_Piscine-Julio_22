/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:57:45 by baltes-g          #+#    #+#             */
/*   Updated: 2022/07/17 17:49:41 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	upcorrecte(int j, int i, int limiters[24], int board[6][6])
{
	int	max;
	int	k;
	int	sum;

	i = 0;
	sum = 0;
	max = 0;
	k = 0;
	while (k < 6)
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

int	downcorrecte(int j, int i, int limiters[24], int board[6][6])
{
	int	max;
	int	k;
	int	sum;

	sum = 0;
	max = 0;
	k = 5;
	while (k >= 0)
	{
		if (board[k][j] > max && board[k][j] != 0)
		{
			max = board[k][j];
			++sum;
		}
		--k;
	}
	if (i == 5)
	{
		if (sum != limiters[6 + j])
			return (0);
	}
	return (1);
}

int	leftcorrecte(int i, int j, int limiters[24], int board[6][6])
{
	int	max;
	int	k;
	int	sum;

	sum = 0;
	max = 0;
	k = 0;
	while (k < 6)
	{
		if (board[i][k] > max && board[i][k] != 0)
		{
			max = board[i][k];
			++sum;
		}
		++k;
	}
	if (j == 5)
	{
		if (sum == limiters[12 + i])
			return (1);
	}
	if (sum <= limiters[12 + i])
		return (1);
	return (0);
}

int	rightcorrecte(int i, int j, int limiters[24], int board[6][6])
{
	int	max;
	int	k;
	int	sum;

	sum = 0;
	max = 0;
	k = 5;
	while (k >= 0)
	{
		if (board[i][k] > max && board[i][k] != 0)
		{
			max = board[i][k];
			++sum;
		}
		--k;
	}
	if (j == 5)
	{
		if (sum != limiters[18 + i])
			return (0);
	}
	return (1);
}
