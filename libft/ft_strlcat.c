/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:41:12 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/15 15:01:02 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (size == 0)
		return (0);
	while (dst[i] && i < size)
		i++;
	j = i;
	while (src[i - j] && i < size - 1)
	{
		dst[i] = src[i - j];
		i++;
	}
	if (j < size)
		dst[i] = '\0';
	return (j + ft_strlen(src));
}

/*#include <string.h>
int	main(void)
{
	char	dest[] = "";
	char	source[] = "Hello la terre";
	printf("%ld\n",ft_strlcat(dest, source, 0));
	printf("La vraie fonction : %d\n", strlcat(dest, source, 0));
	return (0);	
}*/