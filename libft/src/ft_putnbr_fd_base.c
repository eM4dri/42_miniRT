/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:14:37 by emadriga          #+#    #+#             */
/*   Updated: 2022/03/13 15:13:52 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * * Validates base system.
 * * base can´t be empty
 * * base can't size of 1
 * * base can't contain the same character twice
 * * base can't contain + or -;
 * @param base	The base system to validate
 * @return if base system is valid
*/
static int	isokbase(const char *base)
{
	int	i;
	int	k;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		k = i;
		while (base[++k] != 0)
			if (base[i] == base[k])
				return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

/**
 * * Outputs the integer ’n’ to the given file descriptor in a base system.
 * * If base system is invalid nothing is output.
 * @param nbr	The integer to output.
 * @param base	The base system to transform the integer. 
 * @param fd	The file descriptor on which to write.
 * @return index		index to try replace
*/
void	ft_putnbr_fd_base(int nbr, const char *base, int fd)
{
	int				aux;
	unsigned int	n;
	unsigned int	lb;

	if (isokbase(base))
	{
		lb = ft_strlen(base);
		if (nbr < 0)
		{
			n = (unsigned int) nbr * -1;
			ft_putchar_fd('-', fd);
		}
		else
			n = (unsigned int) nbr;
		if (n >= lb)
		{
			ft_putnbr_fd_base(n / lb, base, fd);
			ft_putnbr_fd_base(n % lb, base, fd);
		}
		else
		{
			aux = base[n];
			ft_putchar_fd(aux, fd);
		}
	}
}
