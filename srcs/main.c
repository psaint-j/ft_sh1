/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:44:53 by psaint-j          #+#    #+#             */
/*   Updated: 2015/05/07 15:29:50 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*g_login;
char **g_env;

void	signhandler(int signum)
{
	(void)signum;
	ft_putstr("\n");
	get_prompt(g_login);
}

void	check_sign(void)
{
	signal(SIGINT, signhandler);
}

int		main(int ac, char **av, char **env)
{
	char		**args;
	char		*command;
	int			size;

	size = ft_countab(env);
	g_env = malloc(sizeof(char *) * 2000);
	copy_tab(env, g_env);
	while (42)
	{
		g_login = get_user(g_env);
		check_sign();
		get_prompt(g_login);
		args = get_params();
		get_main(command, args, g_env, size);
	}
	return (0);
}
