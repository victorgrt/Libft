/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:09:52 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/15 14:14:17 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	long int	nb;
	int			len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	long int	nbr;
	char		*str;
	int			i;

	nbr = nb;
	i = len(nbr);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[i] = 48 + (nbr % 10);
		nbr /= 10;
		i--;
	}
	return (str);
}

/*#include <limits.h>
int	main(void)
{
	printf("%s\n", ft_itoa(-623));
	printf("%s\n", ft_itoa(-1234));
	return (0);
}*/