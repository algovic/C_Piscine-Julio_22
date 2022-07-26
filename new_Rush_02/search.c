/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcespede <fcespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:18:03 by fcespede          #+#    #+#             */
/*   Updated: 2022/07/24 12:07:20 by fcespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *key)
{
	int	count;

	count = 0;
	while (key[count] != '\0')
		count++;
	return (count);
}

int	ft_rnum(int num)
{
	int *resultado = malloc(sizeof(num));
	int	i;

	i = 0;
	resultado[i++] = ft_rnum(num / 10);
	while (resultado[i] != 0)
	{
		printf("%d\n", resultado[i]);
		i++;
	}

	return (1);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && *str <= 32)
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}


int	convert(char *str)
{
	int number;	
	
	number = ft_atoi(str);
	ft_rnum(number);
	
	return (number);
}

int	main(void)
{
	char	*name;
	int		i;

	name = "  1234";
	
	convert(name);
/*	printf("%d\n", convert(name));
	printf("ft_atoi: %d\n", ft_atoi(name));
	printf("atoi: %d\n", atoi(name));*/
}
