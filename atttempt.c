/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atttempt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:06:05 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/22 14:18:30 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

//going to wait on that second child but not first i think

static int	child_2(t_args *args, int pipefd[2])
{
	close(0);
	close(pipefd[1]);
	close(1);
	args->outfile = dup2(args->outfile, 1);
	pipefd[0] = dup2(pipefd[0], 0);
	if (execve(args->args2[0], args->args2, NULL) == -1)
	{
		perror(args->com2);
		return (EXIT_FAILURE);
	}
	close(pipefd[0]);
	return (EXIT_SUCCESS);
}

static int	child_1(t_args *args, int pipefd[2])
{
	close(1);
	close(pipefd[0]);
	pipefd[1] = dup2(pipefd[1], 1);
	if (execve(args->args1[0], args->args1, NULL) == -1)
	{
		perror(args->com1);
		return (EXIT_FAILURE);
	}
	close(pipefd[1]);
	return (EXIT_SUCCESS);
}

int	not_main(t_args *args)
{
	pid_t	child1;
	pid_t	child2;
	int		pipefd[2];

	child1 = fork();
	if (child1 == 0)
	{
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		child2 = fork();
		if (child2 == 0)
			exit(child_2(args, pipefd));
		else
			exit(child_1(args, pipefd));
	}
	else
	{
		wait(NULL);
		args = free_args(args);
	}
	return (0);
}
