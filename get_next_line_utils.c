/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcespede <fcespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:42:28 by fcespede          #+#    #+#             */
/*   Updated: 2022/11/26 18:20:02 by fcespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_string;
	int		i;
	int		j;

	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j - 1] != '\n')
	{
		new_string[i] = s2[j];
		j++;
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_strdup(char *s1)
{
	char	*new_string;
	int		idx;

	idx = 0;
	while (s1[idx])
		idx++;
	new_string = malloc(sizeof(char) * (idx + 1));
	if (!new_string)
		return (NULL);
	idx = 0;
	while (s1[idx] != '\0')
	{
		new_string[idx] = ((char *) s1)[idx];
		idx++;
	}
	new_string[idx] = '\0';
	return (new_string);
}

char	*ft_lastphrase(char *phrase, int idx)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * idx);
	while (phrase[i] && phrase[i] != '\n')
	{
		new[i] = phrase[i];
		i++;
	}
	new[i] = '\n';
	new[i + 1] = '\0';
	return (new);
}
