/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:31:12 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/07 18:08:06 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

char	*find_path(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	*temp;
	char	**paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK) != -1)
			return (path);
		free(path);
		i++;
	}
	clean_paths(paths);
	return (cmd);
}

void	split_exec_cmd(char *argv, char **envp)
{
	int		i;
	char	**arg;
	char	*path;
	char	*cmd;

	arg = ft_split(argv, ' ');
	cmd = arg[0];
	path = find_path(envp, cmd);
	if (!path)
	{
		i = 0;
		while (arg[i])
		{
			free(arg[i]);
			i++;
		}
		free(arg);
		ft_error();
	}
	if (execve(path, arg, envp) == -1)
		ft_error();
}

void	clean_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}
