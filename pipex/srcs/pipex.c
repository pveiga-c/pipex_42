/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:28:25 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/07 18:07:24 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child2(int *fd, char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		ft_error();
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	split_exec_cmd(argv[3], envp);
}

void	child1(int *fd, char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		ft_error();
	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	split_exec_cmd(argv[2], envp);
}

void	check_argc(int argc)
{
	if (argc != 5)
	{
		write(1, "Number of arguments is wrong.\n", 29);
		write(1, "\nUsage: ./pipex infile \"cmd1\" \"cmd2\" outfile.\n", 46);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	check_argc(argc);
	if (pipe(fd) == -1)
		ft_error();
	pid1 = fork();
	if (pid1 == -1)
		ft_error();
	if (pid1 == 0)
		child1(fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		ft_error();
	if (pid2 == 0)
		child2(fd, argv, envp);
	waitpid(-1, &status, 0);
	return (0);
}
