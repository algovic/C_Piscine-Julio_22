/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_in_dic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:09:31 by agonzalv          #+#    #+#             */
/*   Updated: 2022/07/24 23:42:44 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void			ft_printnum_short(int num, char *dict);
void			ft_printnum_long(int num, char *dict);
void			ft_print_value(char *key, char *dict);
void			ft_search_content(char *buff, char *key, int i);
int				ft_strlen(char *key);

unsigned int	ft_atoi(const char *str)
{
	unsigned int	res;
	int				negative;

	negative = 1;
	res = 0;
	while (*str && *str <= 32)
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

void	ft_read_dict(char *dict, char *buff)
{
	int		fd;
	char	c;
	int		size_file;

	size_file = 0;
	fd = open(dict, O_RDWR);
	while (read(fd, &c, 1))
		size_file++;
	buff = (char *) malloc((size_file + 1) * sizeof(char));
	if (read(fd, buff, size_file) < 0)
		returt
			n
	else
		buff[size_file] = '\0';
}

int	compare(char *buff, char *key)
{
	int search;

	search = 0;
	while (*buff == key[search] && key[search] != '\0')
	{
		buff++;
		search++;
	}
	if (key[search] == '\0' && (*buff == ' ' || *buff == ':'))
		return (1);
	return (0);
}

int	ft_search_num(char *buff, char *key)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == key[0])
		{
			if (compare(buff, key))
			{
				ft_search_content(buff, key, i);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	ft_find_in_dict(char *dict, char *key)
{
	unsigned int	num;

	num = ft_atoi(key);
	ft_print_num(num);
}
