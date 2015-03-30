/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:53:38 by psaint-j          #+#    #+#             */
/*   Updated: 2015/03/30 21:57:32 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

char	**get_params(void)
{
	char	*line;
	char	**args;

	get_next_line(0, &line);
	if (line)
	{
		args = ft_strsplit(line, ' ');
		return (args);
	}
	return (NULL);
}
