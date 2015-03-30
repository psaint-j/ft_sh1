/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 16:11:37 by psaint-j          #+#    #+#             */
/*   Updated: 2015/03/30 22:33:50 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_myenv(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

char	*get_env(char **env, char *path)
{
	char	**tab;
	char	**args;
	char	*args_return;
	int		i;

	i = 0;
	tab = env;
	args_return = NULL;
	while (tab[i])
	{
		args = ft_strsplit(tab[i], '=');
		if ((ft_strcmp(args[0], path)) == 0)
		{
			args_return = ft_strdup(args[1]);
			return(args_return);
		}
		i++;
	}
	return (args_return);
}

void	print_tab(char **tab, int count)
{
//	int		count;:w
	int		i;

	i = 0;
//	count = ft_countab(tab);
	//	ft_putnbr(count);
	while (i != count)
	{
		ft_putendl(tab[i]);
		i++;
	}
}

void	get_printenv(char **args, char **env, int size)
{
	if ((ft_strncmp(args[0], "printenv", 8)) == 0)
	{
		if (args[1])
		{
			char	*to_return;

			to_return = ft_strdup(get_env(env, args[1]));
			ft_putendl(to_return);
			free(to_return);
		}
		if (args[0] && args[1] == NULL)
			print_tab(env, size);
	}
}

void	push_env(t_env **liste, char *name, char *value)
{
	t_env *new;
	new = (t_env *)malloc(sizeof(*new));
	new->path = ft_strdup(name);
	new->value = ft_strdup(value);
	new->next = *liste;
	*liste = new;
}
