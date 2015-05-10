/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 06:58:23 by psaint-j          #+#    #+#             */
/*   Updated: 2015/05/10 03:06:27 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_prompt(char *login)
{
	ft_printcolor(C_RED, "-");
	ft_printcolor(C_RED, "> ");
	ft_printcolor(C_CYAN, login);
	ft_printcolor(C_WHITE, " ");
}

char	*get_user(char **env)
{
	char	*login;

	login = get_env(env, "USER");
	if (login == NULL)
		login = "$";
	return (login);
}
