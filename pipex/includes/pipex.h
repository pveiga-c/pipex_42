/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:29:59 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/07 18:12:18 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*#############################################################################
#                                  INCLUDES                                   #
#############################################################################*/

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

/*#############################################################################
#                                    PIPEX                                    #
#############################################################################*/

int		main(int argc, char **argv, char **envp);
void	child1(int *fd, char **argv, char **envp);
void	child2(int *fd, char **argv, char **envp);
void	check_argc(int argc);

/*#############################################################################
#                                    SRCS                                     #
#############################################################################*/

void	ft_error(void);
char	*find_path(char **envp, char *cmd);
void	split_exec_cmd(char *cmd, char **envp);
void	clean_paths(char **paths);

#endif