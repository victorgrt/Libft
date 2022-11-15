/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:16:51 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/14 15:20:08 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		deb;
	int		end;

	deb = 0;
	while (s1[deb] && ft_isset(s1[deb], set))
		deb++;
	end = ft_strlen(s1);
	while (end > deb && ft_isset(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - deb + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (deb < end)
	{
		str[i++] = s1[deb++];
	}
	return (str);
}

/*int	main(void)
{
	char tab[] = "!! bonjour !! je m'appelle Roger !!";
	char set[] = "!!";
	printf("%s\n", ft_strtrim(tab, set));
	return (0);
}*/