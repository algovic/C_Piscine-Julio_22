/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcespede <fcespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:09:32 by fcespede          #+#    #+#             */
/*   Updated: 2022/07/24 21:06:58 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_print_num_3digits(char *str)
{
	char c;

	if (*str != '0')
	{
		c = *str;
		ft_search
	}

}

int	ft_strlen(char *key)
{
	int	count;

	count = 0;
	while (key[count] != '\0')
		count++;
	return (count);
}

int	compare(char *buff, char *key, int i)
{
	int	search;
	int	lenght;

	search = 0;
	lenght = ft_strlen(key);
	search = 0;
	if (buff[i + lenght] == 32 || buff[i + lenght] == ':')
	{
		while (buff[i] == key[search] && key[search] != '\0')
		{
			i++;
			search++;
		}
	}
	if (search == lenght)
		return (1);
	return (0);
}

void convert(char *key, int i, int lenght, char *ret)
{
	char str[lenght];
	int j;

	j = 0;
	str[0] = key[i];

	if (lenght > 3)
	{
		key[i] = '1';
		ret = str;
		return;
	}

	while (j < lenght - 1)
	{
		j++;
		str[j] = '0';
	}
	ret = str;
}

void	ft_search_write(char *buff, int i)
{
	int pos;

	while (buff[i++] != ':');
	while (buff[i] == ' ')
		++i;
	pos = i;
	while (buff[i] != 10 && buff[i] != '\0')
	{
		if (buff[i] >= 32 && buff[i] < 127)
			while(buff[i] == ' ')
				i++;
		if (buff[i -1] == ' ' && i > pos)
			write(1, " ", 1);
		write(1, &buff[i], 1);
		i++;
	}
}

int	ft_search(char *dic, char *key)
{
	int fd;
	char *buff;
	char c;
	int nr_bytes = 0;
	int i;
	int search;
	int lenght;
	int ini;
	int j;

	ini = 1;
	i = 0;
	fd = open(dic, O_RDWR);
	while (read(fd, &c, 1))
		nr_bytes++;
	buff = (char *) malloc((nr_bytes + 1) * sizeof(char));
	if (read(fd, buff, nr_bytes) < 0)
		return (-1);
	
	lenght = ft_strlen(key);
	//buff[nr_bytes] = '\0';
//	printf("%zd\n", nr_bytes);
	search = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == key[0])
		{
			if (compare(buff, key, i))
			{
				ft_search_write(buff, i);
				write(1, "\n", 1);
				return (1);
			}
		}
		i++;
	}
	j = 0;
	while (key[j] != '\0')
	{
		i = 0;
		while (buff[i] != '\0')
		{
			if (buff[i] == key[j])
			{
			//	printf("%s\n", convert(key, j, lenght));
				char *aux = "";
				convert(key, j, lenght + 1, aux);
				if (compare(buff, aux, i))
				{
				/*	if (j < 3)
						hundreds(buff, key, j);
					else if (j >= 3 && j < 6)
						thousands(buff, key, j);
					else if (j >= 6 && j < 9)
						millions(buff, key, j);
					else
						// aqui trataremos los billones*/
					ft_search_write(buff, i);
					if (j < lenght + 1)
						write(1, " ", 1);	
					lenght--;								
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}
