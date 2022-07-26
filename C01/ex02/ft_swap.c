/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:44:27 by agonzalv          #+#    #+#             */
/*   Updated: 2022/07/25 21:18:29 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)

{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*int 	main(void)
{

// declarar una variable
	int a;
	int b;
// dar valor a la variable
	a = 42;
	b = 24;
	ft_swap (&a,&b);
	return (0);
}*/
