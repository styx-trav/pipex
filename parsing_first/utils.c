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
