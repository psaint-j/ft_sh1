/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 06:58:23 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/07 19:33:39 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_prompt(char *login)
{
	ft_printcolor(C_RED, "-");
	ft_printcolor(C_RED, "> ");
	ft_printcolor(C_CYAN, login);
	ft_printcolor(C_GREEN, " ");
}

char	*get_user(char **env)
{
	char	*login;

	login = ft_strdup(get_env(env, "USER"));
	return (login);
}
