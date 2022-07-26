/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:54:51 by agonzalv          #+#    #+#             */
/*   Updated: 2022/07/26 17:05:19 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int*b)
{
	int	div;
	int	mod;

		div = *a / *b;
		mod = *a % *b;
		*a = div;
		*b = mod;
}
