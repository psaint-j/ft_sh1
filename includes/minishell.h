/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 01:26:04 by psaint-j          #+#    #+#             */
/*   Updated: 2015/03/30 21:58:45 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFF_SIZE 32

# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <dirent.h>
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
int					get_next_line(int const fd, char **line);
char				*get_env(char **env, char *path);
void				get_prompt(char *login);
char				*get_c(char *line);
void				get_cd(char **args, char **env);
void				check_cd(char *path);
int					ft_countab(char **tab);
void				print_tab(char **tab, int count);
char				*get_user(char **env);
void				get_exec(char **args, char *command);
void				get_printenv(char **args, char **env, int size);
char				**get_params(void);
//void				old_cd(char **args, char **env, char *path);
void				print_myenv(char **env);
char				*get_command(char *arg, char **env);
typedef struct s_env
{
	char			*value;
	char			*path;
	struct s_env *next;
}					t_env;

#endif
