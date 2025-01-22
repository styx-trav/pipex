/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:54:27 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/21 17:01:19 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

int	main(int argc, char **argv)
{
	t_args	*tester;
	int	i;

	if (argc != 5)
		return (0);
	tester = check_comms(argv);
	if (tester)
	{
		printf("here tester ::\nargs1: ");
		i = 0;
		while (tester->args1[i])
		{
			printf("%s -- ", tester->args1[i]);
			i++;
		}
		printf("\nargs2: ");
		i = 0;
		while (tester->args2[i])
		{
			printf("%s -- ", tester->args2[i]);
			i++;
		}
		printf("\ncom1: %s\ncom2: %s\n", tester->com1, tester->com2);
		free_args(tester);
	}
	else
		printf("error somewhere");
	return (0);
}
