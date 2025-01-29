/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libby.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:25:57 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/21 16:27:52 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBY_H
# define LIBBY_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct s_args
{
	char	**args1;
	char	**args2;
	char	*com1;
	char	*com2;
	int		outfile;
	int             infile;
	char    **env;
}	t_args;

//from where.c
int		find_command_reg(t_args *args);

//from where2.c
char	*copy(char *s1, char *write, int i);
char	*join(char *s1, char *s2);
int	find_commands(t_args *args);

//from parsing.c
t_args	*check_comms(char **argv, char **env);

//from utils.c
void	print(char *str);
void	print_nl(char *str);
void	print_zsh_err(char *str, char *name);
void	free_prot(char **tab, int j);
t_args	*free_args(t_args *args);

//from split.c
char	**split(char *str, char c);

//from distrib.c
int		calling(t_args *args);

#endif
