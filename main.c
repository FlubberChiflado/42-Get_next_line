/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcespede <fcespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:02:20 by fcespede          #+#    #+#             */
/*   Updated: 2022/11/24 12:15:05 by fcespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

char	*ft_prueba(char **prueba)
{
	prueba[0] = "caramelo";
	prueba[0] = &prueba[0][1];	
	return (NULL);
}

char	*ft_text(int len)
{
	char	*text;
	int		i = 0;
	char	*new;

	text = "Hola como estas";
	new = malloc(sizeof(char) * 5);
	while (i < len)
	{
		new[i] = text[i];
		i++;
	}
	new[i] = '\0';	
	return (new);	
}

int	main(void)
{
	char	*prueba;
	char	*text;

	prueba = "hola";
	prueba = "adios";
	prueba = "texy";
	printf("%s\n", ft_text(4));
	ft_prueba(&prueba);
	printf("%s\n", prueba);
	return (0);
}
