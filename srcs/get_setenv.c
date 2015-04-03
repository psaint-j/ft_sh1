/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 23:05:20 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/03 21:58:41 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int			ft_strlen_path(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c == '=')
			return (i);
		i++;
	}
	return (i);
}

int			get_line_path(char *name, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if ((strncmp(name, env[i], ft_strlen_path(env[i]))) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void		modif_setenv(char *name, char *value, char **env)
{
	int		i;
	char	*str;

	i = get_line_path(name, env);
	str = ft_strjoin(name, "=");
	str = ft_strjoin(str, value);
	if (i != -1)
	{
		env[i] = ft_strdup(str);
		return ;
	}
	add_setenv(name, value, env, i);
}

void		add_setenv(char *name, char *value, char **env, int check)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strjoin(name, "=");
	str = ft_strjoin(str, value);
	if (check == -1)
	{
		while (env[i])
			i++;
		env[i] = ft_strdup(str);
	}
	i++;
	env[i] = NULL;
}

void		del_unsetenv(char *name, char **env)
{
	char	*str;
	int		len;
	int		i;

	len = get_line_path(name, env);
	i = 0;
	if (len != -1)
	{
		while (env[len])
			len++;
		ft_putnbr(len);
		ft_putchar('\n');
	}
}
