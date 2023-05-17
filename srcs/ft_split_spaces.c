/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:44:49 by nradin            #+#    #+#             */
/*   Updated: 2023/04/13 14:46:19 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_count(char const *s)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (*s)
	{
		if (!ft_isspace(*s) && k == 0)
		{
			k = 1;
			i++;
		}
		else if (ft_isspace(*s))
			k = 0;
		s++;
	}
	return (i);
}

static char	*ft_fill(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * ((finish - start) + 1));
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_spaces(char const *s)
{
	size_t	i;
	size_t	j;
	int		k;
	char	**new;

	new = malloc(sizeof(char *) * (ft_count(s) + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = -1;
	while (i <= ft_strlen(s))
	{
		if (!ft_isspace(s[i]) && k < 0)
			k = i;
		else if ((ft_isspace(s[i]) || i == ft_strlen(s)) && k >= 0)
		{
			new[j++] = ft_fill(s, k, i);
			k = -1;
		}
		i++;
	}
	new[j] = 0;
	return (new);
}
