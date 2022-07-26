/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:31:44 by agonzalv          #+#    #+#             */
/*   Updated: 2022/07/24 23:37:35 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_strlen(char *key)
{
	int	count;

	count = 0;
	while (key[count] != '\0')
		count++;
	return (count);
}

void	ft_search_content(char *buff, char *key, int i)
{
	int	pos;

	while (buff[i] != ':')
		i++;
	while (buff[i] == ' ')
		++i;
	pos = i;
	while (buff[i] != 10 && buff[i] != '\0')
	{
		if (buff[i] >= 32 && buff[i] < 127)
			while (buff[i] == ' ')
				i++;
		if (buff[i -1] == ' ' && i > pos)
			write(1, " ", 1);
		write(1, &buff[i], 1);
		i++;
	}
}

void	ft_print_value(char *key, char *dict)
{
	int		fd;
	int		size_key;
	char	*buff;

	ft_read_dict(dict, buff);
	size_key = ft_strlen(key);
	if ( !ft_search_num(buff, key))
		write(1, "error", 5);
	free(buff);
}

void	ft_printnum_short(unsigned int num, char *dict)
{
	char	tens[3];

	tens[2] = '\0';
	if (num / 100 > 1)
	{
		ft_print_value((num / 100) + '0', dict);
		ft_print_value("100", dict);
	}
	num %= 100;
	if (num / 10 > 1)
	{
		tens[0] = num / 10 + '0';
		tens[1] = '0';
		ft_print_value(tens, dict);
		num %= 10;
	}
	if (num > 9)
	{
		tens[0] = num / 10;
		tens[1] = num % 10;
		ft_print_value(tens, dict);
	}
	else if (num > 0)
		ft_print_value(num % 10 + '0', dict);
}

void	ft_printnum_long(unsigned int num, char *dict)
{
	if (num < 1000)
		ft_printnum_short(num, dict);
	if (num / 1000000000)
	{
		ft_printnum_short(num / 1000000000, dict);
		ft_print_value("1000000000", dict);
		num %= 1000000000;
	}
	if (num / 1000000)
	{
		ft_printnum_short(num / 1000000, dict);
		ft_print_value("1000000", dict);
		num %= 1000000;
	}
	if (num / 1000)
	{
		ft_printnum_short(num / 1000, dict);
		ft_print_value("1000", dict);
		num %= 1000;
	}
	if (num)
		ft_printnum_short(num, dict);
}
