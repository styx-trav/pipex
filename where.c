/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:11:23 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/21 16:23:47 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

static char	*copy(char *s1, char *write, int i)
{
	int	j;

	j = 0;
	while (s1[j])
	{
		write[i + j] = s1[j];
		j++;
	}
	return (write);
}

static char	*join(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	res = malloc(i + j + 1);
	if (!res)
		return (NULL);
	res = copy(s1, res, 0);
	res = copy(s2, res, i);
	res[i + j] = '\0';
	return (res);
}

static int	find_command2(t_args *args)
{
	char	*com;

	com = join("/bin/", args->args2[0]);
	if (!com)
		return (0);
	if (access(com, X_OK) == -1)
	{
		free(com);
		com = join("/sbin/", args->args2[0]);
		if (!com)
			return (0);
		if (access(com, X_OK) == -1)
		{
			free(com);
			if (access(args->args2[0], X_OK) == -1)
				print_zsh_err("command not found", args->args1[0]);
			return (1);
		}
	}
	free(args->args2[0]);
	args->args2[0] = com;
	return (1);
}

int	find_command(t_args *args)
{
	char	*com;

	com = join("/bin/", args->args1[0]);
	if (!com)
		return (0);
	if (access(com, X_OK) == -1)
	{
		free(com);
		com = join("/sbin/", args->args1[0]);
		if (!com)
			return (0);
		if (access(com, X_OK) == -1)
		{
			free(com);
			if (access(args->args1[0], X_OK) == -1)
				print_zsh_err("command not found", args->args1[0]);
			return (1);
		}
	}
	free(args->args1[0]);
	args->args1[0] = com;
	return (find_command2(args));
}
