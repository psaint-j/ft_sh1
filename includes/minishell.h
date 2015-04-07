/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 01:26:04 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/07 21:18:33 by psaint-j         ###   ########.fr       */
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

extern char **g_env;

int					get_next_line(int const fd, char **line);
void				get_prompt(char *login);
void				get_cd(char **args, char **env);
void				get_exec(char **args, char *command, char **env);
void				get_pwd(int ret_dir, char *path, char **env);
char				*get_env(char **env, char *path);
char				*get_user(char **env);
char				*get_c(char *line);
char				*get_command(char *arg, char **env);
char				**get_params(void);
void				check_cd(char *path);
int					ft_countab(char **tab);
void				copy_tab(char **src, char **dst);
void				print_myenv(char **env);
int					get_line_path(char *name, char **env);
void				modif_setenv(char *name, char *value, char **env);
int					get_builtin(char *arg);
void				add_setenv(char *name, char *value, char **env, int check);
void				del_unsetenv(char *name, char **env);
int					ft_strlen_path(char *str);
void				get_main(char *command, char **args, char **g_env, int size);
void				get_check_cd(char **args, char *path, char *old_path, char **env);
void				get_old_pwd(char *old_path, char **env);
//void				old_cd(char **args, char **env, char *path);

#endif
