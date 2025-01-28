/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:54:27 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/21 17:01:19 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

int	main(int argc, char **argv, char **envp)
{
	t_args	*tester;
	int		i;

	if (argc != 5)
		return (0);
	tester = check_comms(argv);
	if (!tester)
		return (0);
	tester->env = envp;
	i = calling(tester);
	return (i);
}
