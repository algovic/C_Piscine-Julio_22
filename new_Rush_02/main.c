/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-atta <ael-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:37:14 by ael-atta          #+#    #+#             */
/*   Updated: 2022/07/24 23:40:28 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_print(char *str);
int		ft_invalid_key(char *str);
void	ft_find_in_dict(char *dict, char *key);

int	main(int argc, char **argv)
{
	char	*dict;
	char	*key;

	if (argc == 3)
	{
		dict = argv[1];
		key = argv[2];
	}
	else if (argc == 2)
	{
		dict = "numbers.dict";
		key = argv[1];
	}
	if (argc != 2 || ft_invalid_key(key))
	{
		ft_print("error\n");
		return (1);
	}
	ft_find_in_dict(dict, key);
	return (0);
}

void	ft_print(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_over_flow(char *str, char *max)
{
	int	it;

	it = 0;
	while (str[it] < 8)
	{
		if (str[it] > max[it])
			return (1);
		it++;
	}
	return (0);
}

int	ft_valid_key(char *str)
{
	int	count;
	int	it;

	count = 0;
	it = 0;
	while (str[it])
	{
		if (str[it] < '0' || str[it] > '9')
			return (0);
		it++;
		count ++;
	}
	it = 0;
	if (count > 9)
		return (0);
	else if (count == 8 && ft_over_flow(str, "4294967295"))
		return (0);
	return (1);
}
