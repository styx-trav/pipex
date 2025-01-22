/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_frees.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:31 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/21 15:25:35 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

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
		while (tab[i + 1] != NULL)
		{
			free(tab[i]);
			i++;
		}
	}
	free(tab);
}

void	free_prot_num(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_args	*free_args(t_args *args)
{
	if (args->args1)
		free_prot(args->args1, -2);
	if (args->args2)
		free_prot(args->args2, -1);
	if (args->com1)
		free(args->com1);
	if (args->com2)
		free(args->com2);
	free(args);
	return (NULL);
}
