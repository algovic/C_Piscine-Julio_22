/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:01:18 by agonzalv          #+#    #+#             */
/*   Updated: 2022/07/22 09:41:30 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	r;

	r = 'z';
	while (r >= 'a')
	{
		write(1, &r, 1);
	r--;
	}
}
