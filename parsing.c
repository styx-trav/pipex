/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:02:00 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/21 14:47:35 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

static void	isfile(t_args *args, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_zsh_err(strerror(errno), filename);
		return ;
	}
	args->infile = fd;
}

static char	*comm(char *command)
{
	char	*result;
	int		i;

	i = 0;
	while (command[i] != '\0' && command[i] != ' ')
		i++;
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (command[i] != '\0' && command[i] != ' ')
	{
		result[i] = command[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static t_args	*make_args(void)
{
	t_args	*send;

	send = (t_args *)malloc(sizeof(t_args));
	if (!send)
		return (NULL);
	send->args1 = NULL;
	send->args2 = NULL;
	send->com1 = NULL;
	send->com2 = NULL;
	send->env = NULL;
	send->outfile = -1;
	send->infile = -1;
	return (send);
}

static void	is_outfile(t_args *args, char *outfile)
{
	int	fd;

	if (access(outfile, F_OK) == -1)
	{
		fd = open(outfile, O_CREAT, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR);
		if (fd == -1)
		{
			print_zsh_err(strerror(errno), outfile);
			return ;
		}
		close(fd);
	}
	if (access(outfile, W_OK) == -1)
	{
		print_zsh_err(strerror(errno), outfile);
		return ;
	}
	args->outfile = open(outfile, O_WRONLY);
	args->outfile = dup2(args->outfile, 7);
}

t_args	*check_comms(char **argv)
{
	t_args	*args;

	args = make_args();
	if (!args)
		return (NULL);
	isfile(args, argv[1]);
	args->com1 = comm(argv[2]);
	if (!args->com1)
		return (free_args(args));
	args->com2 = comm(argv[3]);
	if (!args->com2)
		return (free_args(args));
	args->args1 = split(argv[2], ' ');
	if (!args->args1)
		return (free_args(args));
	args->args2 = split(argv[3], ' ');
	if (!args->args2)
		return (free_args(args));
	if (!find_command(args))
		return (free_args(args));
	is_outfile(args, argv[4]);
	return (args);
}
