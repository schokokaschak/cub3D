/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:23:20 by nradin            #+#    #+#             */
/*   Updated: 2023/04/02 20:26:53 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	char	*test;

	if (s1 && s2)
	{
		tmp = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2));
		if (!tmp)
			return (NULL);
		tmp = ft_strcpy(tmp, (char *)s1);
		test = ft_strcat(tmp, (char *)s2);
		return (test);
	}
	else if (s1 == NULL && s2 != NULL)
		return (ft_strndup((char *)s2, ft_strlen(s2)));
	else if (s2 == NULL && s1 != NULL)
		return (ft_strndup((char *)s1, ft_strlen(s1)));
	else
		return (NULL);
}
