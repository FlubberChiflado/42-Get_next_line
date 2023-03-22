/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcespede <fcespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:09:12 by fcespede          #+#    #+#             */
/*   Updated: 2022/11/26 20:53:04 by fcespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_nl(char *text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (text[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*save_static(char *last_phrase, char *text)
{
	int	len;

	len = ft_strlen(last_phrase) % BUFFER_SIZE;
	if (len != 0)
		return (&text[len]);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*text;
	char static		*last_phrase;
	char			*final_text;
	char			*temp;
	unsigned int	i;

	i = 1;
	if (!last_phrase)
		last_phrase = ft_strdup("");
	text = malloc(sizeof(char) * (BUFFER_SIZE + 1));	
	if (ft_nl(last_phrase) != -1)
	{
		temp = &last_phrase[ft_nl(last_phrase) + 1];
		final_text = ft_lastphrase(last_phrase, ft_nl(last_phrase) + 1);
		last_phrase = malloc(sizeof(char) * ft_strlen(temp));	
		last_phrase = temp;
		return (final_text);
	}
	read(fd, text, BUFFER_SIZE);
	while (ft_nl(text) == -1 && i > 0)
	{
		last_phrase = ft_strjoin(last_phrase, text);
		i = read(fd, text, BUFFER_SIZE);
	}
	if (i > 0)
		last_phrase = ft_strjoin(last_phrase, text);
	final_text = malloc(sizeof(char) * (ft_strlen(last_phrase) + 1));
	final_text = last_phrase;
	last_phrase = save_static(last_phrase, text);
	return (final_text);
}

int	main(void)
{
	int		file;
	int		i;

	i = -1;
	file = open("prueba", O_RDONLY);
	if (file == -1)
	{
		printf("Error");
		return (0);
	}
	while (++i < 9)
	{
		printf("%s", get_next_line(file));
	}
	close(file);
	return (0);
}
