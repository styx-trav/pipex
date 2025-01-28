/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:43:45 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/21 16:45:14 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

void	print(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_nl(char *str)
{
	print(str);
	write(1, "\n", 1);
}

static void	print_min(char *str)
{
	int	i;
	char	a;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			a = str[i] + 32;
			write(1, &a, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	print_zsh_err(char *str, char *name)
{
	print("zsh: ");
	print_min(str);
	print(": ");
	print_nl(name);
}

void	free_prot(char **tab, int j)
{
	int	i;

	i = 0;
	if (j == -1)
	{
		while (tab[i] != NULL)
		{
			free(tab[i]);
			i++;
		}
	}
	else
	{
		while (i < j)
	        {
		        free(tab[i]);
		        i++;
	        }
	}
	free(tab);
}

t_args	*free_args(t_args *args)
{
	if (!args)
		return (NULL);
	if (args->args1)
		free_prot(args->args1, -2);
	if (args->args2)
		free_prot(args->args2, -1);
	if (args->com1)
		free(args->com1);
	if (args->com2)
		free(args->com2);
	if (args->outfile)
		close(args->outfile);
	free(args);
	return (NULL);
}
