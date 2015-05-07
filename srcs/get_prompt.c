/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 06:58:23 by psaint-j          #+#    #+#             */
/*   Updated: 2015/05/07 19:23:08 by psaint-j         ###   ########.fr       */
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

	login = ft_strdup(get_env(env, "USER"));
	if (login == NULL)
		login = "USER";
	return (login);
}
