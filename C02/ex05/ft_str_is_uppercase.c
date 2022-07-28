/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:53:04 by agonzalv          #+#    #+#             */
/*   Updated: 2022/07/27 18:54:39 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*int	main()
{
       printf("%d", ft_str_is_uppercase("ABCDEFGH"));
       printf("\n%d", ft_str_is_uppercase("ABCDEFGHaI"));
       printf("\n%d", ft_str_is_uppercase("-_134556ABCDEFGaH67"));
}*/
