/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:53:38 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/14 15:03:42 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

char	**get_params(void)
{
	char	*line;
	char	**args;
	int		i;
	char	c;

	get_next_line(0, &line);
	if (line)
	{
		i = 0;
		while (line[i] != '\0')
		{
			c = line[i];
			if (c == 9)
				line[i] = ' ';
			i++;
		}
		args = ft_strsplit(line, ' ');
		return (args);
	}
	return (NULL);
}
