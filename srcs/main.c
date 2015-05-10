/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:44:53 by psaint-j          #+#    #+#             */
/*   Updated: 2015/05/10 03:53:19 by psaint-j         ###   ########.fr       */
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
	int			size;
	char		*command;

	size = ft_countab(env);
	g_env = malloc(sizeof(char *) * 2000);
	copy_tab(env, g_env);
	init_env(g_env);
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

void	init_env(char **env)
{
	if (*env == NULL)
	{
		modif_setenv("ITERM_PROFILE", "Default", env);
		modif_setenv("COLORFGB","7;0", env);
		modif_setenv("USER", "$", env);
		modif_setenv("PATH", "/nfs/zfs-student-4/users/2014/psaint-j/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin", env);
		modif_setenv("TERM","xterm-256color", env);
	}
}
